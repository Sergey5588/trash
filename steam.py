import requests
import json
response = requests.get("https://steamcommunity.com/inventory/76561199163822783/2923300/2?l=russian&count=30")


print(json.dumps(response.json(),sort_keys=True, indent=4))
print(response.json().assets.ammount)
