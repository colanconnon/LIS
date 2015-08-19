//
//  LIS.cpp
//  LIS
//
//  Created by colan connon on 4/20/15.
//  Copyright (c) 2015 colan connon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> readTextFile(){
    /*
     function for reading from a file
     */
    vector<int> inputArray;
    ifstream file;
    file.open("incseq.txt");
    int intToReadFromFile;
    if (file.is_open()) {
        while (!file.eof()) {
            file >> intToReadFromFile;
            inputArray.push_back(intToReadFromFile);
        }
        
    }
    file.close();
    return inputArray;
}
int longest_increasing_seq(vector<int> inputArray){
    /*
     function that takes in a vector, and determines the longest incresing sequence
     */
    // hold the max value to return at the end
    int maxValue = 0;
    //array for holding the values in longest inc seq table
    vector<int> lisList;
    
    for(int i = 0; i < inputArray.size(); i++){
        lisList.push_back(1);
        //init the whole arraylist with ones with the size of the input
    }
    
    for (int i = 0;i < inputArray.size(); i++) {
        for(int j = 0; j < i; j++){
            if(inputArray.at(i) > inputArray.at(j))
             {
                if(lisList.at(i) < (lisList.at(j) + 1)){
                    //increment the value in the list
                    lisList.at(i) = lisList[j] + 1;
                   
                }
            }
        }
    }
    for(int i = 0; i < inputArray.size(); i++){
        if(maxValue < lisList.at(i)){
            // find the max value in lis table, to return and that value because it is the longest increasing subsequence
            maxValue = lisList.at(i);
        }
    }
    return maxValue;
}

void printSubSeq(vector<int> inputArray){
    /*
        this function creates an array that holds the longest inc subseq
        and then prints the array
     */
    int max = 0;
    vector<int> listToPrint;
    for (int i = 0; i < inputArray.size(); i++) {
        if( max < inputArray.at(i)){
            max = inputArray.at(i);
            listToPrint.push_back(max);
        }
    }
    cout << "Longest subsequence is ";
    for (int j = 0; j < listToPrint.size(); j++) {
        cout << listToPrint.at(j) << ", ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    //get the input from the file
    vector<int>  inputArray = readTextFile();
    //calculate the longest subseq
    cout << "Longest increasing seq is " << longest_increasing_seq(inputArray) << endl;
    
    printSubSeq(inputArray);
    
    return 0;
}
