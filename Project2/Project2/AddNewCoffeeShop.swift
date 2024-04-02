//
//  AddNewCoffeeShop.swift
//  Project2
//
//  Created by Lisa Hisamura on 4/1/24.
//

import SwiftUI

// View for adding a new coffee shop to the list

struct AddNewCoffeeShop: View {
    
    @StateObject var coffeeShopList : CoffeeShopList
    
    @State private var isStudyFriendly = true
    @State private var name: String = ""
    @State private var city: String = ""
    
    // Creates the view with the necessary form fields (to enter informatiion for new coffee shop) and button to add the new coffee shop
    
    var body: some View {
        Form {
            Section(header: Text("Coffee Shop Details")) {
                
                DataInput(title: "Name", userInput: $name)
                DataInput(title: "City", userInput: $city)
                
                Toggle(isOn: $isStudyFriendly) {
                    Text("Is Study Friendly")
                        .font(.headline)
                } .padding()
            }
            
            Button(action: addNewCoffeeShop) {
                
                Text("Add Coffee Shop")
            }
        }
    }
    
    // Function to add the new offee shop to an existing list
    
    func addNewCoffeeShop () {
        let newCoffeeShop = CoffeeShop(id: UUID().uuidString,
    name: name, city: city, isStudyFriendly: isStudyFriendly, imageName: "car.fill")
        
        coffeeShopList.coffeeshops.append(newCoffeeShop)
    }
    
}

// Subview for the data input fields in the form

struct DataInput: View {
    var title: String
    @Binding var userInput: String
    
    var body: some View {
        VStack (alignment: HorizontalAlignment.leading) {
            Text(title)
                .font(.headline)
            TextField("Enter \(title)", text: $userInput)
                .textFieldStyle(RoundedBorderTextFieldStyle())
        }
        .padding(EdgeInsets())
    }
}



#Preview {
    AddNewCoffeeShop(coffeeShopList : CoffeeShopList(coffeeshops : coffeeShopData))
}
