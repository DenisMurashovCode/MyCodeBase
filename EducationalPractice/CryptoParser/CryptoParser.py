import sqlite3
import requests
from bs4 import BeautifulSoup as BS



r=requests.get("https://coinmarketcap.com")
html = BS(r.content, 'html.parser')


Name = html.find("table", class_="sc-beb003d5-3 ieTeVa cmc-table").find_all("p", {"class": "sc-4984dd93-0 kKpPOn", "data-sensors-click": "true"})
Symbol = html.find("table", class_="sc-beb003d5-3 ieTeVa cmc-table").find_all( class_="sc-4984dd93-0 iqdbQL coin-item-symbol")
Price = html.find("table", class_="sc-beb003d5-3 ieTeVa cmc-table").find_all("a", {"class": "cmc-link"})
Market_cap = html.find("table", class_="sc-beb003d5-3 ieTeVa cmc-table").find_all( class_="sc-edc9a476-0 fXzXSk")

list=[]
for i in range(1,len(Price),4):
    list.append(Price[i].text)

del list[10:]



with sqlite3.connect('db/database.db') as db:
    cursor = db.cursor()

    cursor.execute(''' CREATE TABLE IF NOT EXISTS Crypto
    (name TEXT, symbol TEXT, price TEXT, market_cap TEXT)
        ''')

    cursor.execute("DELETE FROM Crypto")



    for i in range(len(list)):
        cryptoToInsert = [
            (Name[i].text, Symbol[i].text, list[i], Market_cap[i].text)
        ]

        cursor.executemany('''
                        INSERT INTO Crypto(name, symbol, price, market_cap)
                        VALUES (?,?,?,?)
                        ''',cryptoToInsert)


    

    cursor.execute("SELECT * FROM Crypto")
    
    
    for i in cursor:
        print(i)

    
    Name = input("\nВведите название криптовалюты : ")
    while(Name!="exit"):
        Name_crypto = (Name,)

        cursor.execute("SELECT * FROM Crypto WHERE name=?", Name_crypto)
        print("\n  Name  |  Symbol  |  Price  |  Market Cap\n\n",cursor.fetchone())
        Name = input("\n\n(для выхода введите exit)\nВведите название криптовалюты : ")
    if(Name=="exit"):
        print("Сеанс завершён")
    db.commit()
