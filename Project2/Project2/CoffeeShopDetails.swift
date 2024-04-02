//
//  CoffeeShopDetails.swift
//  Project2
//
//  Created by Lisa Hisamura on 4/1/24.
//

import SwiftUI

// View for looking at the details of each coffee shop

struct CoffeeShopDetails: View {
    let selectedCoffeeShop: CoffeeShop
    
    @State private var buttonColor: Color = .blue
    @State private var buttonText: String = "Add to Favorites"
    
    var body: some View {
        // Outlines what details of the coffee shop will be displayed and how they will look
        Form {
            Section(header: Text("Coffee Shop Details")) {
                Image (selectedCoffeeShop.imageName)
                    .resizable()
                    .cornerRadius(12.0)
                    .aspectRatio(contentMode: .fit)
                    .padding()
                
                Text(selectedCoffeeShop.city)
                    .font(.headline)
                
                HStack {
                    Text("Study Friendly?")
                        .font(.headline)
                    Spacer()
                    Image(systemName: selectedCoffeeShop.isStudyFriendly ? "checkmark.circle" : "xmark.circle")
                }
        
                // Animation: Button changes color and text when pressed
                Button(action: {
                    buttonColor = buttonColor == .blue ? .red : .blue
                    buttonText = buttonText == "Add to Favorites" ? "Added!" : "Add to Favorites"
                }) {
                    Text(buttonText)
                        .foregroundColor(.white)
                        .padding()
                        .background(buttonColor)
                        .cornerRadius(8)
                }
                
            }
        }
        
    }
    
    
}

#Preview {
    CoffeeShopDetails(selectedCoffeeShop: coffeeShopData[0])
}
