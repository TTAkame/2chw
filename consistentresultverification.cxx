#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"json.hpp"


void findMismatch(nlohmann::json jObj1, nlohmann::json jObj2, int arraySize, int numSamples) {
   for (int i = 1;i <= numSamples; i++) {
      std::string sampleNum;
      if (i < 10) {
         sampleNum = "Sample0" + std::to_string(i);
      } else {
         sampleNum = "Sample" + std::to_string(i);
      }
         std::cout << sampleNum << std::endl;
         for (int j = 0;j < arraySize; j++) {
            if (jObj2[sampleNum][j] != jObj1[sampleNum][j]) {
               std::cout << jObj2[sampleNum][j] << " not equal to " << jObj1[sampleNum][j] << std::endl;
            } else {
               std::cout << "not mismatch" << std::endl;
            }
         }
   }
}

int main(int argc, char** argv) {

   // declare input file names
   std::ifstream file1(argv[1]);
   std::ifstream file2(argv[2]);

   //declare json objects
   nlohmann::json sample;
   nlohmann::json almostSample;

   //parse file to json object
   file1 >> sample;
   file2 >> almostSample;

   //read metadata
   int arraySize = sample["metadata"]["arraySize"];
   int numSamples = sample["metadata"]["numSamples"];

   //findMismatch funciton

   /* std::cout << sample.dump(2) << std::endl; */

   findMismatch(almostSample,sample,arraySize,numSamples);

   file1.close();
   file2.close();

   return 0;
}
