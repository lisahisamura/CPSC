//
//  ContentView.swift
//  Project2
//
//  Created by Lisa Hisamura on 4/1/24.
//

import SwiftUI

// Content View - the list of coffee shops

struct ContentView: View {
    // Create state object of coffee shop list
    @StateObject private var coffeeShopList: CoffeeShopList = CoffeeShopList(coffeeshops: coffeeShopData)
    var body: some View {
        // Display the list of coffee shops
        NavigationView {
            List {
                ForEach(coffeeShopList.coffeeshops) { coffeeshop in
                    ListCell(coffeeshop: coffeeshop)
                }
                // States for deleting and moving the list items
                .onDelete(perform: deleteItem)
                .onMove(perform: moveItem)
            }
            .navigationTitle(Text("Coffee Shops"))
            .navigationBarItems(leading: NavigationLink (destination: AddNewCoffeeShop(coffeeShopList: self.coffeeShopList)) {
                Text("+")
                    .font(.system(size: 24))
            }, trailing: EditButton())
        }
    }
    
    // Function for deleting an item off the list
    func deleteItem(at offset: IndexSet) {
        coffeeShopList.coffeeshops.remove(atOffsets: offset)
    }
    
    // Function for moving an item within the list
    func moveItem(from source: IndexSet, to destination: Int) {
        coffeeShopList.coffeeshops.move(fromOffsets: source, toOffset: destination)
    }
}

#Preview {
    ContentView()
}

// Outlines what information is included in each list cell and where it leads to when pressed
struct ListCell: View {
    var coffeeshop: CoffeeShop
    var body: some View {
        NavigationLink (destination: CoffeeShopDetails(selectedCoffeeShop: coffeeshop)) {
            HStack {
                Image(coffeeshop.imageName)
                    .resizable()
                    .aspectRatio (contentMode: .fit)
                    .frame(width: 100, height: 60)
                
                Text(coffeeshop.name)
                
            }
        }
    }
}

