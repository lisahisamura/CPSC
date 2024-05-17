// @file CafeDetails.swift
// @brief View that shows details of each cafe
// @author Lisa Hisamura hisamura@chapman.edu
// @CPSC356 Final Project

import SwiftUI

struct CafeDetails: View {
    let selectedCafe: Cafe
    @State private var isWritingReview = false
    @State private var reviewText = ""
    @EnvironmentObject var visitedCafes: VisitedCafes
    
    // Design of how cafe details are displayed
    var body: some View {
        Form {
            Section {
                Text(selectedCafe.name)
                    .font(.system(size: 24))
                    .bold()
                    .padding()
                Image(selectedCafe.imageName)
                    .resizable()
                    .cornerRadius(12.0)
                    .aspectRatio(contentMode: .fit)
                    .padding()
                
                Text(selectedCafe.city)
                    .font(.headline)
                
                HStack {
                    Text("Study Friendly?")
                        .font(.headline)
                    Spacer()
                    Image(systemName: selectedCafe.isStudyFriendly ? "checkmark.circle" : "xmark.circle")
                }
            }
            
            // Conditional statements based on whether the user has visited the cafe or not and whether there is already a written review there or not
            .onAppear {
                if let review = visitedCafes.cafes.first(where: { $0.id == selectedCafe.id })?.review {
                    reviewText = review
                    isWritingReview = review.isEmpty
                }
            }
            // If the user has visited the cafe and has not written a review yet, they can add a new review
            if cafeVisited(selectedCafe) {
                if isWritingReview {
                    Section(header: Text("Write a Review").font(.system(size: 18))) {
                        TextEditor(text: $reviewText)
                            .frame(height: 100)
                            .padding()
                            .font(.system(size: 18))
                        
                        Button(action: {
                            visitedCafes.updateReview(for: selectedCafe, with: reviewText)
                            isWritingReview = false
                        }) {
                            Text("Submit Review")
                                .foregroundColor(.white)
                                .padding()
                                .background(Color.init(red: 0.859, green: 0.424, blue: 0.251))
                                .cornerRadius(8)
                                .font(.system(size: 18))
                        }
                        .padding()
                    }
                // If the user has visited the cafe and has already written a review, they can view that review and edit it
                } else {
                    Section(header: Text("Your Review").font(.system(size: 18))) {
                        Text(reviewText)
                            .padding()
                            .font(.system(size: 18))
                        
                        Button(action: {
                            isWritingReview = true
                        }) {
                            Text(reviewText.isEmpty ? "Add Review" : "Edit Review")
                                .font(.system(size: 18))
                        }
                        .padding()
                    }
                }
            }
        }
    }
    
    // Function that checks whether the user has visited the cafe based on whether that cafe id is in the visitedCafes array
    private func cafeVisited(_ cafe: Cafe) -> Bool {
        return visitedCafes.cafes.contains { $0.id == cafe.id }
    }
}



#Preview {
    CafeDetails(selectedCafe: cafeData[0])
}
