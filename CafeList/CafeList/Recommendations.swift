// @file Recommendations.swift
// @brief Recommendations tab that randomly generates a cafe from a list of cafe recommendations
// @author Lisa Hisamura hisamura@chapman.edu
// @CPSC356 Final Project


import SwiftUI

struct Recommendations: View {
    @StateObject private var recommendationsList: RecommendationsList = RecommendationsList(recommendations: recommendationsData)
    @State private var randomRecommendation: Cafe?
    
    var body: some View {
        ZStack {
            Color.init(red: 0.81, green: 0.86, blue: 0.74)
            
            // If the user has generated a random cafe, show that cafe. Else, show them the button to generate a cafe recommendation.
            VStack {
                if let cafe = randomRecommendation {
                    Cell(cafe: cafe)
                } else {
                    Text("Press the button to find a cafe \nyou might like.").bold()
                        .padding()
                        .font(.system(size: 24))
                }
                Button(action: {
                    randomRecommendation = getRandomCafe()
                }) {
                    Text("Show me a new cafe!").font(.system(size: 24))
                }
                .padding(5)
            }
        }
        .edgesIgnoringSafeArea(.all)
    }
    
    // Function to generate a random number and retrieve that index position in the array of cafe recommendations
    func getRandomCafe() -> Cafe? {
        return recommendationsList.recommendations.randomElement()
    }
}

// Design the appearance of the Recommendations view
struct Cell: View {
    var cafe: Cafe
    var body: some View {
        NavigationLink(destination: CafeDetails(selectedCafe: cafe)) {
            VStack {
                Section(header: Text(cafe.name).font(.system(size: 36)).bold()
                            .foregroundColor(.black)
                            .opacity(1.0)) {
                    Image(cafe.imageName)
                        .resizable()
                        .cornerRadius(12.0)
                        .aspectRatio(contentMode: .fit)
                        .padding()
                    
                    Text(cafe.city).font(.system(size: 24))
                        .font(.headline)
                        .foregroundColor(.black)
                        .opacity(1.0)
                    
                    HStack {
                        Text("Study Friendly?").font(.system(size: 24))
                            .foregroundColor(.black)
                            .opacity(1.0)
                        Image(systemName: cafe.isStudyFriendly ? "checkmark.circle" : "xmark.circle")
                    }
                    .padding(5)
                }
            }
        }
    }
}

#Preview {
    Recommendations()
}


