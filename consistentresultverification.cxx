#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"json.hpp"
nlohmann::json findMismatch(nlohmann::json jObj1, nlohmann::json jObj2, int arraySize, int numSamples) {
   nlohmann::json mismatches;
   for (int i = 1;i <= numSamples; i++) {
      std::string sampleNum;
      if (i < 10) {
         sampleNum = "Sample0" + std::to_string(i);
      } else {
         sampleNum = "Sample" + std::to_string(i);
      }
      for (int j = 0;j < arraySize; j++) {
         if (jObj2[sampleNum][j] != jObj1[sampleNum][j]) {
            mismatches[std::to_string(j)] = {jObj2[sampleNum][j], jObj1[sampleNum][j]};
         }
      }
   }
   return mismatches;
}

/* nlohmann::json findMismatch(nlohmann::json jObj1, nlohmann::json jObj2, int arraySize, int numSamples) { */
/*    nlohmann::json result; */

/*    for (int i = 1;i <= numSamples; i++) { */
/*       std::string sampleNum; */
/*       if (i < 10) { */
/*          sampleNum = "Sample0" + std::to_string(i); */
/*       } else { */
/*          sampleNum = "Sample" + std::to_string(i); */
/*       } */
/*          /1* std::cout << sampleNum << std::endl; *1/ */
/*          nlohmann::json mismatches; */
/*          int errorCount = 0; */
/*          for (int j = 0;j < arraySize; j++) { */
/*             if (jObj2[sampleNum][j] != jObj1[sampleNum][j]) { */
/*                mismatches.push_back({jObj2[sampleNum][j], jObj1[sampleNum][j]}); */
/*                errorCount++; */
/*                std::cout << errorCount << std::endl; */
/*             } */
/*          } */
/*          result[sampleNum] = mismatches; */
/*    } */
/*    return result; */
/* } */

int main(int argc, char** argv) {

   // declare input file names
   std::ifstream file1(argv[1]);
   std::ifstream file2(argv[2]);

   //declare json objects
   nlohmann::json sample;
   nlohmann::json almostSample;
   nlohmann::json mismatch;
   nlohmann::json result;

   //parse file to json object
   file1 >> sample;
   file2 >> almostSample;
   result[argv[1]] = sample;
   result[argv[2]] = almostSample;

   //read metadata
   int arraySize = sample["metadata"]["arraySize"];
   int numSamples = sample["metadata"]["numSamples"];

   //findMismatch funciton
   mismatch = findMismatch(almostSample,sample,arraySize,numSamples);
   result["Mismatches"] = mismatch;

   std::cout << result.dump(2) << std::endl;

   file1.close();
   file2.close();

   return 0;
}
