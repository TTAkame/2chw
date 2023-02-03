#include<iostream>
#include<stdlib.h>
#include "json.hpp"
#include<vector>
#include<string>
#include<fstream>

using json = nlohmann::json;


int main(int argc, char** argv) {

	std::ifstream file(argv[1]);
	nlohmann::json data = nlohmann::json::parse(file);

//std::cout << data << std::endl<<std::endl;

	int i,a,b,count=0,tinverse = 0;
	json outpt;
	
	
	
	std::string sz = data["metadata"]["arraySize"].dump();

	std::string ns = data["metadata"]["numSamples"].dump();
	
	
	for (auto it = data.begin(); it != std::prev(data.end(),1) ; ++it){

	std::vector<int> spl = it.value().get<std::vector<int>>();

	for (i=0;i<spl.size()-1;i++){
	
		a = spl[i];
		b = spl[i+1];
	
//std::cout<<it.key()<<std::endl;

		if(a>b){
			count ++;
			outpt[it.key()]["ConsecutiveInversions"][std::to_string(count)]={a,b};
//std::cout<<a<<std::endl<<b;
			
		a = 0;
		b = 0;
		
		
		}
	}
	if(count!=0){
		outpt[it.key()]["sample"]=it.value();
		tinverse +=1;
	}
	count = 0;
}
	
	outpt["metadata"]["arraysize"]=sz;
	outpt["metadata"]["file"] = "SampleExample.json";
	outpt["metadata"]["numSamples"]=ns;
	outpt["metadata"]["sampleWithInversions"]=tinverse;
	
	
	std::cout<< outpt <<std::endl;
	
	return 1;


}
