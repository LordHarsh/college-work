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
    item_name = input("Enter name of the item to search: ")
    data = db.execute("SELECT * FROM database WHERE name LIKE ?", ("%"+item_name+"%",))  
    print(item_name)
    print(list(data))
    if len(list(data)) == 0:        
        print("Nothing matches the given name")
    else:
        len(list(data))
        print_data(db, data)


def add_stock(db):
    """ This method takes user input then adds items accordingly """
    print("\nItems currently in database")
    data_list = db.execute("select * from database")
    print_data(db, data_list)
    while True:
        user_input = input("\nENTER 1 TO ADD ITEM ALREADY IN LIST\nENTER 2 TO ADD NEW ITEM\nENTER 3 TO SEARCH\nENTER 0 TO GO BACK\n")
        match user_input:
            case "1":
                u2 = input("\nENTER ID OF THE ITEM TO ADD OR ENTER 0 TO GO BACK\n")
                if u2 == '0':
                    continue
                data_list = db.execute("SELECT * FROM database WHERE id=?", u2)
                if not data_list:
                    print("\nID NOT IN LIST\n")
                    continue
                print_data(db, data_list)
                quan = db.execute("SELECT quantity FROM database WHERE id=?", u2)
                new_quan = list(quan)[0][0] + int(input("Enter the quantity of this item to add: "))
                db.execute("UPDATE database SET quantity=? WHERE id=?", (new_quan, u2))
                print(f"{new_quan} items added!")
                db.commit()
            case "2":
                item_name = input("Enter name of the item: ").title()
                item_price = input("Enter price of the item: ")
                item_quantity = input("Enter quantity of the item: ")
                db.execute("INSERT INTO database (name, quantity, price) VALUES(?, ?, ?)", (item_name, item_quantity, item_price))
                print(f"{item_quantity} items added!")
                db.commit()
            case "3":
                search(db)
            case "0":
                print("Returning.....\n")
                return
            case _:
                print("Wrong Input")


def sell_stock(db):

    pass


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
    db.execute("CREATE TABLE IF NOT EXISTS add_history (id INTEGER AUTO_INCREMENT NOT NULL PRIMARY KEY, item_id INTEGER NOT NULL, quantity NUMERIC NOT NULL, price NUMERIC NOT NULL)")
    db.execute("CREATE TABLE IF NOT EXISTS sold_history (id INTEGER AUTO_INCREMENT NOT NULL PRIMARY KEY, item_id INTEGER NOT NULL, quantity NUMERIC NOT NULL, price NUMERIC NOT NULL)")
    while True:
        user_input = input("\nENTER 1 to add stock,\nENTER 2 to sell stock OR\nENTER 0 to exit\n")
        if user_input == "1":
            add_stock(db)
        elif user_input == "2":
            sell_stock(db)
            break
        elif user_input == "0":
            break
        else:
            print("Wrong Input\n")
if __name__ == "__main__":
    main()