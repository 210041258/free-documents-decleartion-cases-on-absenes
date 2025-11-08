#Task 1: Parse the JSON data and print the store’s "name" and its "city" location.

import json

# Load the JSON data
json_data = '''{
    "store": {
        "name": "Tech Hub",
        "location": {
            "city": "San Francisco",
            "address": {
                "street": "123 Market St",
                "postalCode": "94103"
            }
        },
        "departments": [
            {
                "name": "Electronics",
                "products": [
                    {
                        "id": 201,
                        "name": "Laptop",
                        "brand": "BrandX",
                        "price": 999.99,
                        "specifications": {
                            "processor": "Intel i7",
                            "memory": "16GB",
                            "storage": "512GB SSD"
                        }
                    },
                    {
                        "id": 202,
                        "name": "Smartphone",
                        "brand": "BrandY",
                        "price": 799.99,
                        "specifications": {
                            "screenSize": "6.1 inches",
                            "battery": "4000mAh",
                            "camera": "12MP"
                        }
                    }
                ]
            },
            {
                "name": "Accessories",
                "products": [
                    {
                        "id": 301,
                        "name": "Wireless Mouse",
                        "brand": "BrandZ",
                        "price": 29.99,
                        "specifications": {
                            "batteryLife": "12 months",
                            "connectivity": "Bluetooth"
                        }
                    },
                    {
                        "id": 302,
                        "name": "Keyboard",
                        "brand": "BrandX",
                        "price": 49.99,
                        "specifications": {
                            "layout": "QWERTY",
                            "connectivity": "Wireless"
                        }
                    }
                ]
            }
        ]
    }
}
'''

data = json.loads(json_data)

# Extract the store's name and city location
store_name = data["store"]["name"]
city = data["store"]["location"]["city"]

print(f"Store Name: {store_name}")
print(f"City: {city}")

# what i learn at all the tasks deoumented here in initalization of the tasks
# i just have been rembered by teh python strucuture on interaction with json 
# which the head of the stucture of the  json is the key of the json object presented as [] key
# if i want to extract one of the instead head i can use [] the looped on the structured 
# else if i can't expect the strucuture i can make the biggest loop to check the value on the strucutere as next on the heads of it 
# the heads present with it's name with for the next one 
# next() is from the json imported on the pyhton 
# product defined as the strucure as variable to hold the data for the each next operation as check condition and so on 

