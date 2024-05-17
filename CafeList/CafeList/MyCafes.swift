// @file MyCafes.swift
// @brief MyCafes view, which consists of a list for tracking cafes that the user wants to visit, and another for cafes that they have visited.
// @author Lisa Hisamura hisamura@chapman.edu
// @CPSC356 Final Project

import SwiftUI
import Combine

struct MyCafes: View {
    
    // Cases for switching between the 'Want to Go' list and the 'Visited' list
    enum ListType {
        case wantToGo
        case visited
    }
    
    @State private var selectedList: ListType = .wantToGo
    @StateObject private var cafeList: CafeList = CafeList(cafes: cafeData)
    @StateObject private var visitedCafes: VisitedCafes = VisitedCafes()
    
    var body: some View {
        NavigationView {
            VStack {
                // Allows for switching between the two lists
                Picker(selection: $selectedList, label: Text("List")) {
                    Text("Want to go").tag(ListType.wantToGo).font(.system(size: 18))
                    Text("Visited").tag(ListType.visited).font(.system(size: 18))
                }
                .pickerStyle(SegmentedPickerStyle())
                .padding()
                
                // Written descriptions on how to use the swipe features
                switch selectedList {
                case .wantToGo:
                    Text("Swipe right to move the cafe to Visited!\nSwipe left to delete the cafe.").font(.system(size: 18))
                case .visited:
                    Text("Swipe left to delete the cafe.").font(.system(size: 18))
                }
                
                
                List {
                    switch selectedList {
                        
                    // The list of cafes the user wants to visit
                    case .wantToGo:
                        Section(header: Text("Want to go").font(.system(size: 18))) {
                            ForEach(cafeList.cafes) { cafe in
                                ListCell(cafe: cafe)
                                    // Swiping right allows user to move the cafe to 'Visited'
                                    .swipeActions(edge: .leading) {
                                        Button("Move to Visited") {
                                            moveCafeToVisited(cafe)
                                        }
                                        .tint(.green)
                                    }
                                    // Swiping left allows user to delete the cafe
                                    .swipeActions(edge: .trailing) {
                                        Button("Delete") {
                                            deleteItem(cafe)
                                        }
                                        .tint(.red)
                                    }
                            }
                            .onDelete { indexSet in
                                indexSet.forEach { index in
                                    deleteItem(cafeList.cafes[index])
                                }
                            }
                        }
                    // The list of cafes the user has visited
                    case .visited:
                        Section(header: Text("Visited").font(.system(size: 18))) {
                            ForEach(visitedCafes.cafes) { cafe in
                                ListCell(cafe: cafe)
                                    // Swiping left allows user to delete the cafe
                                    .swipeActions(edge: .leading) {
                                        Button("Delete") {
                                            deleteItem(cafe)
                                        }
                                        .tint(.red)
                                    }
                            }
                            .onDelete { indexSet in
                                indexSet.forEach { index in
                                    deleteItem(cafeList.cafes[index])
                                }
                            }
                        }
                    }
                }
                
                // 'Add cafe' button that leads to the user to the screen to add a new cafe to the list
                NavigationLink(destination: AddCafe(cafeList: self.cafeList)) {
                    Text("Add a cafe!")
                        .font(.system(size: 24))
                        .padding()
                        .foregroundColor(Color.init(red: 0.859, green: 0.424, blue: 0.251))
                }
                
                .navigationTitle("My Cafes")
                .navigationBarItems(trailing: EditButton().font(.system(size: 18))).foregroundColor(Color.init(red: 0.22, green: 0.34, blue: 0.14))
                
            }.background(Color.init(red: 0.81, green: 0.86, blue: 0.74))

        }
        .environmentObject(cafeList)
        .environmentObject(visitedCafes)
    }
    
    func deleteItem(_ cafe: Cafe) {
        if let index = cafeList.cafes.firstIndex(where: { $0.id == cafe.id }) {
            cafeList.cafes.remove(at: index)
        }
    }
    
    // The function for moving a cafe to the 'Visited' list - used ChatGPT
    private func moveCafeToVisited(_ cafe: Cafe) {
        if let index = cafeList.cafes.firstIndex(where: { $0.id == cafe.id }) {
            let removedCafe = cafeList.cafes.remove(at: index)
            visitedCafes.cafes.append(removedCafe)
            print("Visited Cafes: \(visitedCafes.cafes)")
        }
    }
}


#Preview {
    MyCafes()
}

// Design of each list cell of cafes
struct ListCell: View {
    var cafe: Cafe
    var body: some View {
        NavigationLink(destination: CafeDetails(selectedCafe: cafe)) {
            HStack {
                Image(cafe.imageName)
                    .resizable()
                    .aspectRatio(contentMode: .fit)
                    .frame(width: 100, height: 60)
                Text(cafe.name).font(.system(size: 18))
            }
        }
    }
}

class VisitedCafes: ObservableObject {
    @Published var cafes: [Cafe] = [] // Provide a default value
    
//    init(cafes: [Cafe] = []) {
//        self.cafes = cafes
//    }
    
    func updateReview(for cafe: Cafe, with text: String) {
        if let index = cafes.firstIndex(where: { $0.id == cafe.id }) {
            cafes[index].review = text
        } else {
            var newCafe = cafe
            newCafe.review = text
            cafes.append(newCafe)
        }
    }
}
