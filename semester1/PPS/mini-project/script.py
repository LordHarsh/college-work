import os
import sqlite3
import sys
import pandas as pd

def print_data(db, data_list):

    data = {
        "name" : [],
        "id" : [],
        "quantity" : [],
        "price" : []
    }
    for i in data_list:
        data["id"].append(i[0])
        data["name"].append(i[1])
        data["quantity"].append(i[2])
        data["price"].append(i[3])
        
    df = pd.DataFrame(data)
    df = df.set_index("id")
    df['price'] = df['price'].apply(lambda x: "\u20B9{:.2f}".format(x))
    print(df)

def search(db):
    item_name = input("ENTER NAME OF THE ITEM TO SEARCH OR\nJUST PRESS ENTER KEY TO VIEW WHOLE DATABASE: ")
    data = db.execute("SELECT * FROM database WHERE name LIKE ?", ("%"+item_name+"%",))  
    l = list(data)
    if len(l) == 0:        
        print("Nothing matches the given name")
    else:
        print_data(db, l)

def add_stock(db):
    """ This method takes user input to adds items accordingly """
    print("\nITEMS CURRENTLY IN DATABASE")
    data_list = db.execute("select * from database")
    print_data(db, data_list)
    while True:
        user_input = input("\nENTER 1 TO ADD ITEM ALREADY IN LIST\nENTER 2 TO ADD NEW ITEMS\nENTER 3 TO SEARCH\nENTER 0 TO GO BACK\n")
        match user_input:
            case "1":
                u2 = input("\nENTER ID OF THE ITEM TO ADD OR ENTER 0 TO GO BACK\n")
                if u2 == '0':
                    continue
                data_list = list(db.execute("SELECT * FROM database WHERE id=?", (u2,)))
                if not data_list:
                    print("\nID NOT IN LIST\n")
                    continue
                print_data(db, data_list)
                quan = list(db.execute("SELECT quantity FROM database WHERE id=?", (u2,)))[0][0]
                user_quan = int(input("ENTER QUANTITY OF THIS ITEM TO ADD: "))
                new_quan = quan + user_quan
                item_price = float(input("ENTER THE WHOLE SALE PRICE OF THE ITEM: "))
                db.execute("UPDATE database SET quantity=? WHERE id=?", (new_quan, u2))
                price = user_quan * item_price
                db.execute("INSERT INTO history (item_id, quantity, transaction_price, transaction_type) VALUES(?,?,?,?)", (u2, user_quan, price, "ADDED"))
                print(f"{user_quan} ITEMS ADDED!\nPrice = \u20B9{price:.2f}")
                db.commit()
            case "2":
                item_name = input("ENTER NAME OF THE ITEM: ").title()
                if item_name == '0':
                    continue
                item_price = float(input("ENTER PRICE OF THE ITEM: "))
                item_quantity = int(input("ENTER QUANTITY OF THE ITEM: "))
                ws_price = float(input("ENTER THE WHOLE SALE PRICE OF THE ITEM: "))
                db.execute("INSERT INTO database (name, quantity, price) VALUES(?, ?, ?)", (item_name, item_quantity, item_price))
                price = ws_price * item_quantity
                item_id = list(db.execute("SELECT id FROM database WHERE name=?", (item_name,)))[0][0]
                
                db.execute("INSERT INTO history (item_id, quantity, transaction_price, transaction_type) VALUES(?,?,?,?)", (item_id, item_quantity, price, "ADDED"))
                print(f"{item_quantity} ITEMS ADDED!\nPrice = \u20B9{price:.2f}")
                db.commit()
            case "3":
                search(db)
            case "0":
                print("RETURNING.....\n")
                return
            case _:
                print("WRONG INPUT\n")

def sell_stock(db):
    """ This method takes user input to sell items accordingly """
    print("\nITEMS CURRENTLY IN DATABASE")
    data_list = db.execute("select * from database")
    print_data(db, data_list)
    while True:
        user_input = input("\nENTER 1 TO VIEW DATABASE\nENTER 2 TO SELL ITEMS\nENTER 3 TO SEARCH\nENTER 0 TO GO BACK\n")
        match user_input:
            case "1":
                print("\nITEMS CURRENTLY IN DATABASE")
                data_list = db.execute("SELECT * FROM database")
                print_data(db, data_list)
            case "2":
                u2 = input("\nENTER ID OF THE ITEM TO ADD OR ENTER 0 TO GO BACK\n")
                if u2 == '0':
                    continue
                data_list = list(db.execute("SELECT * FROM database WHERE id=?", (u2,)))
                if not data_list:
                    print("\nID NOT IN LIST\n")
                    continue
                print_data(db, data_list)
                avail_quan = list(db.execute("SELECT quantity FROM database WHERE id=?", (u2,)))[0][0]
                sell_quan = int(input("ENTER QUATITY OF THIS ITEM TO SELL: "))
                if sell_quan > avail_quan:
                    print(f"ONLY {avail_quan} ARE AVAILABLE IN STOCK.")
                    continue
                db.execute("UPDATE database SET quantity=? WHERE id=?", ((avail_quan-sell_quan), u2))
                price = list(db.execute("SELECT price FROM database WHERE id=?", (u2,)))[0][0]
                bill = sell_quan * price
                db.execute("INSERT INTO history (item_id, quantity, transaction_price, transaction_type) VALUES(?,?,?,?)", (u2, sell_quan, bill, "SOLD"))
                print(f"\n{sell_quan} ITEMS SOLD\nBILL = \u20B9{bill:.2f}")
                db.commit()
            case "3":
                search(db)
            case "0":
                print("RETURNING.....\n")
                return
            case _:
                print("WRONG INPUT\n")

def history(db):
    data_list = list(db.execute("SELECT history.id, history.item_id, name, history.quantity, transaction_price, time, transaction_type FROM history LEFT JOIN database ON history.item_id = database.id"))
    data = {
        "Id" : [],
        "Item Id" : [],
        "Item Name" : [],
        "Quantity" : [],
        "Transaction Price" : [],
        "Time" : [],
        "Transaction Type" : []
    }
    for i in data_list:
        data['Id'].append(i[0])
        data['Item Id'].append(i[1])
        data['Item Name'].append(i[2])
        data['Quantity'].append(i[3])
        data['Transaction Price'].append(i[4])
        data["Time"].append(i[5])
        data['Transaction Type'].append(i[6])
    
    df = pd.DataFrame(data)
    df = df.set_index("Id")
    df['Transaction Price'] = df['Transaction Price'].apply(lambda x: "\u20B9{:.2f}".format(x))
    print(df)


def get_db():
    dir = os.getcwd()
    if len(sys.argv) == 2:
        name = sys.argv[1]
    else:
        name = "general_store.db"
    file_path = os.path.join(sys.path[0], name)
    return sqlite3.connect(file_path)


def main ():
    ''' main program '''
    db = get_db()
    db.execute("CREATE TABLE IF NOT EXISTS database (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, quantity NUMERIC NOT NULL, price NUMERIC NOT NULL)")
    db.execute("CREATE TABLE IF NOT EXISTS history (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, item_name TEXT, item_id INTEGER NOT NULL, quantity NUMERIC NOT NULL, transaction_price NUMERIC NOT NULL, time DATETIME default CURRENT_TIMESTAMP, transaction_type TEXT NOT NULL, FOREIGN KEY(item_id, item_name) REFERENCES database(id, name))")
    while True:
        user_input = input("\nENTER 1 TO ADD STOCK,\nENTER 2 TO SELL STOCK\nENTER 3 TO VIEW HISTORY\nENTER TO ENTER 0 TO EXIT\n")
        if user_input == "1":
            add_stock(db)
        elif user_input == "2":
            sell_stock(db)
        elif user_input == "3":
            history(db)
        elif user_input == "0":
            print("------THANK YOU------")
            break
        else:
            print("Wrong Input\n")
if __name__ == "__main__":
    main()
