// @file AddCafe.swift
// @bruef View for adding a new cafe to the MyCafes list
// @author Lisa Hisamura hisamura@chapman.edu
// @CPSC356 Final Project

import SwiftUI

struct AddCafe: View {
    
    @StateObject var cafeList : CafeList
    @State private var isStudyFriendly = true
    @State private var name: String = ""
    @State private var city: String = ""
    
    // Creates the view with the necessary form fields (to enter information for adding a new cafe
    
    var body: some View {
        Form {
            Section(header: Text("Cafe Details").font(.system(size: 18))) {
                
                DataInput(title: "Name", userInput: $name).font(.system(size: 18))
                DataInput(title: "City", userInput: $city).font(.system(size: 18))
                
                Toggle(isOn: $isStudyFriendly) {
                    Text("Is Study Friendly").font(.system(size: 18))
                        .font(.headline)
                } .padding()
            }
            
            // A button to add the new cafe
            Button(action: addCafe) {
                Text("Add Cafe")
                    .font(.system(size: 24))
                    .foregroundColor(.white)
                    .padding()
                    .background(Color.init(red: 0.859, green: 0.424, blue: 0.251))
                    .cornerRadius(8)
            }
        }
    }
    
    // Function to add the new cafe to an existing list
    
    func addCafe () {
        let newCafe = Cafe(id: UUID().uuidString,
    name: name, city: city, isStudyFriendly: isStudyFriendly, imageName: "cup.and.saucer")
        
        cafeList.cafes.append(newCafe)
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
    AddCafe(cafeList : CafeList(cafes : cafeData))
}
