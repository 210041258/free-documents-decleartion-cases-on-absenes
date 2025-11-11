import json


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

electronics = next(department for department in data["store"]["departments"] if department["name"] == "Electronics")

smartphone = next(product for product in electronics["products"] if product["name"] == "Smartphone")

smartphone["price"] = 749.99

updated_json = json.dumps(data, indent=4)
print(updated_json)
