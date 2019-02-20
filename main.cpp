#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

int main(void) {
	ifstream input_file("raw_proxies.txt");
	
	vector<string> iplist;
	string raw_ip;
	
	while(getline(input_file, raw_ip)) {
		string ip;
		int port;
		
		istringstream stream_ip(raw_ip);
		
		getline(stream_ip, ip, ':');
		if (find(iplist.begin(), iplist.end(), ip) != iplist.end()) {
			continue;
		}
		else {
			cout<<ip<<endl;
			iplist.push_back(ip);
		}
	}
	input_file.close();
	
	ofstream output_file("iplist.txt");
	
	if (output_file.is_open()) {
		for (int i=0; i <= iplist.size()-1; i++) {
			output_file<<iplist[i]<<endl;
		}
	}
	else {
		cout<<endl<<endl<<"Unable to output file.";
	}
	cout<<endl<<endl<<"IP List extracted from proxies.";
	output_file.close();
	
}
