import requests
import json
import steammarket as sm

STEAM_ID = 76561199163822783 #Sergey5588
#STEAM_ID = 76561199075767816 #kpekep404
#STEAM_ID = #Sergey5302
CUR = "RUB" # e.g. USD
response = requests.get("https://steamcommunity.com/inventory/{}/2923300/2?l=russian&count=5000".format(STEAM_ID))

items = json.loads(response.text)
#print(json.dumps(response.json(),sort_keys=True, indent=4))
allItems = []
unique = []
for i in items["assets"]:
    allItems.append(i["classid"])

for i in items["descriptions"]:
    unique.append([allItems.count(i["classid"]), i["market_hash_name"]])
#print(allItems)

#item = sm.get_item(2923300, "Musicnana", currency='RUB')
#print(item)
s = 0
print("name   ".rjust(20), "total owned".rjust(5), "each price".rjust(20), "total price".rjust(20))
for i in unique:

    name = i[1]
    total = i[0]
    price = sm.get_item(2923300, name, currency=CUR)
    low = price["lowest_price"][:-5]
    low = low.replace(",",".")
    low = float(low)
    s+=low*total
    #print(low)
    print(i[1].rjust(20),(str(i[0])+"x").rjust(5), (str(low)).rjust(20), (str(round(low*total, 2))).rjust(20))
#print(unique)
print("total: "+ str(s))
