//on my honor i have neither given nor received unauthorized help on this assignment


#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<math.h>
using namespace std;

void init(vector<string> &k ,vector<int> &v,vector<string> &instructions) {
	string line;
	ifstream file;
	file.open("C:\\Drive D\\MS UF\\Sem 2\\Embedded Systems\\Project2\\original.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			    instructions.push_back(line);
				int index, match;
				match = 0;
				for (int i = 0;i < k.size();i++)
				{
					if (k[i] == line) {
						index = i;
						match = 1;
					}
				}
				if (match)
					v[index] += 1;
				else {
					v.push_back(1);
					k.push_back(line);
				}

			}
		
	   }
}

void sort_dict(vector<string> &k,vector<int> &v,string *s) {
	string temp;
	int max;
	int index;
	for (int j = 0; j < 16;j++) {
		max = 0;
		for (int i = 0;i < v.size()-1;i++) {
			if (v[i] > max) {
				temp = k[i];
				index = i;
				max = v[i];
			}
		}
		v[index] = 0;
		s[j] = temp;
	}

}

bool RLE(int count,string &file) {
	int bitlen = 6;
	if (count < 2 || count >9) {
		return false;
	}
	else {
		file += "001";
		switch (count) {
		case 2: file += "001";
			break;
		case 3: file += "010";
			break;
		case 4: file += "011";
			break;
		case 5: file += "100";
			break;
		case 6: file += "101";
			break;
		case 7: file += "110";
			break;
		case 8: file += "111";
			break;
		}
	/*	for (int i = 0; i < (32 - bitlen);i++)
		{
			file << "0";
		}*/
		//file << endl;
		return true;
	}
}

bool DI(string arr,const string* dict, string &file) {
	int bitlen = 7;
	int index = -1;
	int match = 0;
	string comp;
	for(int i=0;i<16;i++){
		match = 0;
		comp = dict[i];
		for (int j = 0;j < 32;j++) {
			if (arr[j] == comp[j])
				match++;
		}	
		if (match == 32) {
			index = i;
		}
	}
	if (index >= 0)
	{
		file += "111";
		switch (index) {
		case 0: file+= "0000";
			break;
		case 1: file += "0001";
			break;
		case 2: file += "0010";
			break;
		case 3: file += "0011";
			break;
		case 4: file += "0100";
			break;
		case 5: file += "0101";
			break;
		case 6: file += "0110";
			break;
		case 7: file += "0111";
			break;
		case 8: file += "1000";
			break;
		case 9: file += "1001";
			break;
		case 10: file += "1010";
			break;
		case 11: file += "1011";
			break;
		case 12: file += "1100";
			break;
		case 13: file += "1101";
			break;
		case 14: file += "1110";
			break;
		case 15: file += "1111";
			break;
			}
		//file << endl;
		return true;
	}
	else
		return false;
}

bool one_bmis(string arr, const string* dict,string &file){
	int bitlen = 9;
	int index = 0;
	int dict_index = 0;
	int mis = 0;
	string comp;
	for (int j = 0;j < 16;j++) {
		comp = dict[j];
		dict_index = j;
		mis = 0;
		for (int i = 0; i < arr.length();i++) {
			if(arr[i]!=comp[i])
			{
				mis++;
				index = i;
			}
		}
		if (mis == 1)
			break;
	}
	if (mis != 1) {
		return false;
	}
	else {
		file += "011";	
		switch (index) {
		case 0: file += "00000";
			break;
		case 1: file += "00001";
			break;
		case 2: file += "00010";
			break;
		case 3: file += "00011";
			break;
		case 4: file += "00100";
			break;
		case 5: file += "00101";
			break;
		case 6: file += "00110";
			break;
		case 7: file += "00111";
			break;
		case 8: file += "01000";
			break;
		case 9: file += "01001";
			break;
		case 10: file += "01010";
			break;
		case 11: file += "01011";
			break;
		case 12: file += "01100";
			break;
		case 13: file += "01101";
			break;
		case 14: file += "01110";
			break;
		case 15: file += "01111";
			break;
		case 16: file += "10000";
			break;
		case 17: file += "10001";
			break;
		case 18: file += "10010";
			break;
		case 19: file += "10011";
			break;
		case 20: file += "10100";
			break;
		case 21: file += "10101";
			break;
		case 22: file += "10110";
			break;
		case 23: file += "10111";
			break;
		case 24: file += "11000";
			break;
		case 25: file += "11001";
			break;
		case 26: file += "11010";
			break;
		case 27: file += "11011";
			break;
		case 28: file += "11100";
			break;
		case 29: file += "11101";
			break;
		case 30: file += "11110";
			break;
		case 31: file += "11111";
			break;
			break;
		}
		switch (dict_index) {
		case 0: file += "0000";
			break;
		case 1: file += "0001";
			break;
		case 2: file += "0010";
			break;
		case 3: file += "0011";
			break;
		case 4: file += "0100";
			break;
		case 5: file += "0101";
			break;
		case 6: file += "0110";
			break;
		case 7: file += "0111";
			break;
		case 8: file += "1000";
			break;
		case 9: file += "1001";
			break;
		case 10: file += "1010";
			break;
		case 11: file += "1011";
			break;
		case 12: file += "1100";
			break;
		case 13: file += "1101";
			break;
		case 14: file += "1110";
			break;
		case 15: file += "1111";
			break;
		}
		/*for (int i = 0; i < (32 - bitlen);i++)
		{
			file << "0";
		}*/
		return true;
	}
}

bool two_bcmis(string arr,const string* dict, string &file) {
	int index = 0;
	int bitlen = 9;
	int dict_index = 0;
	int cons_mis = 0;
	int mis = 0;
	string comp;
	for (int j = 0;j < 16;j++) {
		comp = dict[j];
		mis = 0;
		cons_mis = 0;
		for (int i = 0; i < arr.length()-1;i++) {
			if (arr[i] != comp[i] && (arr[i+1]!=comp[i+1]))
			{
				cons_mis++;
				index = i;
			}
			else if (arr[i] != comp[i])
			{
				mis++;
			}
		}
		if (cons_mis == 1 && mis==0){
			dict_index = j;
			break;
		}

	}
	if (cons_mis != 1 || mis>0) {
		return false;
	}
	else {
		file += "100";
		switch (index) {
		case 0: file += "00000";
			break;
		case 1: file += "00001";
			break;
		case 2: file += "00010";
			break;
		case 3: file += "00011";
			break;
		case 4: file += "00100";
			break;
		case 5: file += "00101";
			break;
		case 6: file += "00110";
			break;
		case 7: file += "00111";
			break;
		case 8: file += "01000";
			break;
		case 9: file += "01001";
			break;
		case 10: file += "01010";
			break;
		case 11: file += "01011";
			break;
		case 12: file += "01100";
			break;
		case 13: file += "01101";
			break;
		case 14: file += "01110";
			break;
		case 15: file += "01111";
			break;
		case 16: file += "10000";
			break;
		case 17: file += "10001";
			break;
		case 18: file += "10010";
			break;
		case 19: file += "10011";
			break;
		case 20: file += "10100";
			break;
		case 21: file += "10101";
			break;
		case 22: file += "10110";
			break;
		case 23: file += "10111";
			break;
		case 24: file += "11000";
			break;
		case 25: file += "11001";
			break;
		case 26: file += "11010";
			break;
		case 27: file += "11011";
			break;
		case 28: file += "11100";
			break;
		case 29: file += "11101";
			break;
		case 30: file += "11110";
			break;
		case 31: file += "11111";
			break;
		}
		switch (dict_index) {
		case 0: file += "0000";
			break;
		case 1: file += "0001";
			break;
		case 2: file += "0010";
			break;
		case 3: file += "0011";
			break;
		case 4: file += "0100";
			break;
		case 5: file += "0101";
			break;
		case 6: file += "0110";
			break;
		case 7: file += "0111";
			break;
		case 8: file += "1000";
			break;
		case 9: file += "1001";
			break;
		case 10: file += "1010";
			break;
		case 11: file += "1011";
			break;
		case 12: file += "1100";
			break;
		case 13: file += "1101";
			break;
		case 14: file += "1110";
			break;
		case 15: file += "1111";
			break;
		}
	/*	for (int i = 0; i < (32 - bitlen);i++)
		{
			file << "0";
		}*/
		//file << endl;
		return true;
	}

}

bool four_bcmis(string arr, const string* dict, string &file) {
	int index = 0;
	int bitlen = 9;
	int dict_index = 0;
	int mis = 0;
	int cons_mis = 0;
	string comp;
	for (int j = 0;j < 16;j++) {
		comp = dict[j];
		dict_index = j;
		mis = 0;
		cons_mis = 0;
		for (int i = 0; i < arr.length() - 3;i++) {
			if (arr[i] != comp[i] && (arr[i + 1] != comp[i + 1]) && (arr[i + 2] != comp[i + 2]) && (arr[i + 3] != comp[i + 3]))
			{
				cons_mis++;
				index = i;
			}
			else if (arr[i] != comp[i]) {
				mis++;
			}
		}
		if (cons_mis == 1 && mis ==0)
			break;
	}
	if (cons_mis != 1 || mis >0) {
		return false;
	}
	else {
		file += "101";
		switch (index) {
		case 0: file += "00000";
			break;
		case 1: file += "00001";
			break;
		case 2: file += "00010";
			break;
		case 3: file += "00011";
			break;
		case 4: file += "00100";
			break;
		case 5: file += "00101";
			break;
		case 6: file += "00110";
			break;
		case 7: file += "00111";
			break;
		case 8: file += "01000";
			break;
		case 9: file += "01001";
			break;
		case 10: file += "01010";
			break;
		case 11: file += "01011";
			break;
		case 12: file += "01100";
			break;
		case 13: file += "01101";
			break;
		case 14: file += "01110";
			break;
		case 15: file += "01111";
			break;
		case 16: file += "10000";
			break;
		case 17: file += "10001";
			break;
		case 18: file += "10010";
			break;
		case 19: file += "10011";
			break;
		case 20: file += "10100";
			break;
		case 21: file += "10101";
			break;
		case 22: file += "10110";
			break;
		case 23: file += "10111";
			break;
		case 24: file += "11000";
			break;
		case 25: file += "11001";
			break;
		case 26: file += "11010";
			break;
		case 27: file += "11011";
			break;
		case 28: file += "11100";
			break;
		case 29: file += "11101";
			break;
		case 30: file += "11110";
			break;
		case 31: file += "11111";
			break;
		}
		switch (dict_index) {
		case 0: file += "0000";
			break;
		case 1: file += "0001";
			break;
		case 2: file += "0010";
			break;
		case 3: file += "0011";
			break;
		case 4: file += "0100";
			break;
		case 5: file += "0101";
			break;
		case 6: file += "0110";
			break;
		case 7: file += "0111";
			break;
		case 8: file += "1000";
			break;
		case 9: file += "1001";
			break;
		case 10: file += "1010";
			break;
		case 11: file += "1011";
			break;
		case 12: file += "1100";
			break;
		case 13: file += "1101";
			break;
		case 14: file += "1110";
			break;
		case 15: file += "1111";
			break;
		}
	/*	for (int i = 0; i < (32 - bitlen);i++)
		{
			file << "0";
		}*/
		//file << endl; 
		return true;
	}

}

bool two_bmis(string arr, const string* dict, string &file) {
	int index0 = 0;
	int index1 = 0;
	int bitlen = 14;
	int dict_index = 0;
	int mis = 0;
	string comp;
	for (int j = 0;j < 16;j++) {
		comp = dict[j];
		dict_index = j;
		mis = 0;
		index0 = 0;
		index1 = 0;
		for (int i = 0; i < arr.length();i++) {
			if (arr[i] != comp[i] )
			{
				mis++;
				if (index0 == 0)
					index0 = i;
				else if (index1 == 0)
					index1 = i;
			}
		}
		if (mis == 2)
			break;
	}
	if (mis != 2) {
		return false;
	}
	else {
		file += "110";
		switch (index0) {
		case 0: file += "00000";
			break;
		case 1: file += "00001";
			break;
		case 2: file += "00010";
			break;
		case 3: file += "00011";
			break;
		case 4: file += "00100";
			break;
		case 5: file += "00101";
			break;
		case 6: file += "00110";
			break;
		case 7: file += "00111";
			break;
		case 8: file += "01000";
			break;
		case 9: file += "01001";
			break;
		case 10: file += "01010";
			break;
		case 11: file += "01011";
			break;
		case 12: file += "01100";
			break;
		case 13: file += "01101";
			break;
		case 14: file += "01110";
			break;
		case 15: file += "01111";
			break;
		case 16: file += "10000";
			break;
		case 17: file += "10001";
			break;
		case 18: file += "10010";
			break;
		case 19: file += "10011";
			break;
		case 20: file += "10100";
			break;
		case 21: file += "10101";
			break;
		case 22: file += "10110";
			break;
		case 23: file += "10111";
			break;
		case 24: file += "11000";
			break;
		case 25: file += "11001";
			break;
		case 26: file += "11010";
			break;
		case 27: file += "11011";
			break;
		case 28: file += "11100";
			break;
		case 29: file += "11101";
			break;
		case 30: file += "11110";
			break;
		case 31: file += "11111";
			break;
		}
		switch (index1) {
		case 0: file += "00000";
			break;
		case 1: file += "00001";
			break;
		case 2: file += "00010";
			break;
		case 3: file += "00011";
			break;
		case 4: file += "00100";
			break;
		case 5: file += "00101";
			break;
		case 6: file += "00110";
			break;
		case 7: file += "00111";
			break;
		case 8: file += "01000";
			break;
		case 9: file += "01001";
			break;
		case 10: file += "01010";
			break;
		case 11: file += "01011";
			break;
		case 12: file += "01100";
			break;
		case 13: file += "01101";
			break;
		case 14: file += "01110";
			break;
		case 15: file += "01111";
			break;
		case 16: file += "10000";
			break;
		case 17: file += "10001";
			break;
		case 18: file += "10010";
			break;
		case 19: file += "10011";
			break;
		case 20: file += "10100";
			break;
		case 21: file += "10101";
			break;
		case 22: file += "10110";
			break;
		case 23: file += "10111";
			break;
		case 24: file += "11000";
			break;
		case 25: file += "11001";
			break;
		case 26: file += "11010";
			break;
		case 27: file += "11011";
			break;
		case 28: file += "11100";
			break;
		case 29: file += "11101";
			break;
		case 30: file += "11110";
			break;
		case 31: file += "11111";
			break;
		}
		switch (dict_index) {
		case 0: file += "0000";
			break;
		case 1: file += "0001";
			break;
		case 2: file += "0010";
			break;
		case 3: file += "0011";
			break;
		case 4: file += "0100";
			break;
		case 5: file += "0101";
			break;
		case 6: file += "0110";
			break;
		case 7: file += "0111";
			break;
		case 8: file += "1000";
			break;
		case 9: file += "1001";
			break;
		case 10: file += "1010";
			break;
		case 11: file += "1011";
			break;
		case 12: file += "1100";
			break;
		case 13: file += "1101";
			break;
		case 14: file += "1110";
			break;
		case 15: file += "1111";
			break;
		}
	/*	for (int i = 0; i < (32 - bitlen);i++)
		{
			file << "0";
		}*/
		//file << endl;
		return true;
	}
}

bool bitmask(string arr, const string* dict, string & file) {
	vector<int> misind;
	int dict_index;
	string mask="1";
	string comp;
	for (int j = 0;j < 16;j++) {
		comp = dict[j];
		dict_index = j;
		misind.clear();
		for (int i = 0; i < arr.length();i++)
		{
			if (arr[i] != comp[i]) {
				misind.push_back(i);			
			}	
		}
		if(misind.size()<5 && (misind[misind.size()-1] -misind[0]) <4)
			break;
	}
	if (misind.size() < 5 && (misind[misind.size()-1] - misind[0]) < 4) {
		file += "010";
		switch (misind[0]){
		case 0: file += "00000";
			break;
		case 1: file += "00001";
			break;
		case 2: file += "00010";
			break;
		case 3: file += "00011";
			break;
		case 4: file += "00100";
			break;
		case 5: file += "00101";
			break;
		case 6: file += "00110";
			break;
		case 7: file += "00111";
			break;
		case 8: file += "01000";
			break;
		case 9: file += "01001";
			break;
		case 10: file += "01010";
			break;
		case 11: file += "01011";
			break;
		case 12: file += "01100";
			break;
		case 13: file += "01101";
			break;
		case 14: file += "01110";
			break;
		case 15: file += "01111";
			break;
		case 16: file += "10000";
			break;
		case 17: file += "10001";
			break;
		case 18: file += "10010";
			break;
		case 19: file += "10011";
			break;
		case 20: file += "10100";
			break;
		case 21: file += "10101";
			break;
		case 22: file += "10110";
			break;
		case 23: file += "10111";
			break;
		case 24: file += "11000";
			break;
		case 25: file += "11001";
			break;
		case 26: file += "11010";
			break;
		case 27: file += "11011";
			break;
		case 28: file += "11100";
			break;
		case 29: file += "11101";
			break;
		case 30: file += "11110";
			break;
		case 31: file += "11111";
			break;
		}
		for (int i = 1;i < misind.size();i++)
		{
			switch (misind[i] - misind[i - 1]) {
			case 1: mask += "1";
				break;
			case 2: mask += "01";
				break;
			case 3: mask += "001";
				break;
			}
		}
		if (mask.length() < 4) {
			for (int i = 0;i < 4 - mask.length();i++) {
				mask += "0";
		 }
		}
		file += mask;
		switch (dict_index) {
		case 0: file += "0000";
			break;
		case 1: file += "0001";
			break;
		case 2: file += "0010";
			break;
		case 3: file += "0011";
			break;
		case 4: file += "0100";
			break;
		case 5: file += "0101";
			break;
		case 6: file += "0110";
			break;
		case 7: file += "0111";
			break;
		case 8: file += "1000";
			break;
		case 9: file += "1001";
			break;
		case 10: file += "1010";
			break;
		case 11: file += "1011";
			break;
		case 12: file += "1100";
			break;
		case 13: file += "1101";
			break;
		case 14: file += "1110";
			break;
		case 15: file += "1111";
			break;
		}
		//file << endl;
		return true;
	}
	else 
		return false;
	

}

string compress(const vector<string> instructions,const string *final_dict) {
	int count=0;
	string file;
	for (int i = 0; i < instructions.size();i++) {
		if (i == 0) {
			if (RLE(count, file))
				count = 0;
			else if (DI(instructions[i], final_dict, file));
			else if (one_bmis(instructions[i], final_dict, file));
			else if (two_bcmis(instructions[i], final_dict, file));
			else if (four_bcmis(instructions[i], final_dict, file));
			else if (bitmask(instructions[i], final_dict, file));
	        else if (two_bmis(instructions[i], final_dict, file));
			else {
				file += "000";
				file += instructions[i];
				//file += endl;
			}
		}
		else if (i > 0 && i < instructions.size()) {
			if (instructions[i] == instructions[i - 1] && count<8) {
				count++;
			}
			else {
				if (RLE(count, file)) {
					count = 0;
				}
				if (DI(instructions[i], final_dict, file));
				else if (one_bmis(instructions[i], final_dict, file));
				else if (two_bcmis(instructions[i], final_dict, file));
				else if (four_bcmis(instructions[i], final_dict, file));
				else if (bitmask(instructions[i], final_dict, file));
				else if (two_bmis(instructions[i], final_dict, file));
				else {
					file += "000";
					file += instructions[i];
				}
					
			}
		}

	}
	return file;
}

void write_comp(string binary, const string *final_dict) {
	ofstream file;
	file.open("cout.txt");
	int padding = 32 - binary.length() % 32;
	for(int i=0;i<padding;i++)
	{
		binary += '0';
	}
	for (int i = 0;i < binary.length();i+=32)
	{
		for (int j = i;j < i + 32;j++) {
			file << binary[j];
		}
		file << endl;
	}
	file << "xxxx" << endl;
	for (int i = 0;i < 16;i++) {
		file << final_dict[i] << endl;
	}
}

void read_comp(string &binary, string *ref_dict) {
	ifstream file;
	file.open("C:\\Drive D\\MS UF\\Sem 2\\Embedded Systems\\Project2\\compressed.txt");
	
	string line;
	int i = 0;
	int bin_flag = 0;
	if (file.is_open()) {
		while (getline(file, line)) {

			if (line == "xxxx"){
				bin_flag = 1;
			}

			if (bin_flag == 0) {
				binary += line;
			}
			else {
				if (i < 16 && line !="xxxx"){
					ref_dict[i] = line;
					i++;
				}
			}
		}
	}

	return;
}

string get_dict(string position,const string *ref_dict) {
	if (position == "0000")
		return ref_dict[0];
	else if (position == "0001")
		return ref_dict[1];
	else if (position == "0010")
		return ref_dict[2];
	else if (position == "0011")
		return ref_dict[3];
	else if (position == "0100")
		return ref_dict[4];
	else if (position == "0101")
		return ref_dict[5];
	else if (position == "0110")
		return ref_dict[6];
	else if (position == "0111")
		return ref_dict[7];
	else if (position == "1000")
		return ref_dict[8];
	else if (position == "1001")
		return ref_dict[9];
	else if (position == "1010")
		return ref_dict[10];
	else if (position == "1011")
		return ref_dict[11];
	else if (position == "1100")
		return ref_dict[12];
	else if (position == "1101")
		return ref_dict[13];
	else if (position == "1110")
		return ref_dict[14];
	else if (position == "1111")
		return ref_dict[15];
	else
		return "error";
	}

int index_conv(const string pos) {
	int index = 0;
	for (int i = pos.length()-1;i >= 0;i--) {
		index += (int(pos[i])-48) * pow(2, pos.length()-1-i);
	}
	return index;
}

void decompress(string &binary, const string *ref_dict, vector<string> &decomp) {
	char c1,c2,c3;
	string operation;
	string output;
	stringstream ss;
	ss.str(binary);
	while (!ss.eof()) {
		ss >> c1;
		ss >> c2;
		ss >> c3;
		operation = c1;
		operation += c2;
		operation += c3;
		if (operation == "000") {
			output = "";
			for (int i = 0;i < 32;i++) {
				ss >> c1;
				output += c1;
			}
			decomp.push_back(output);
		}
		else if (operation == "001") {
			output = "";
			for (int i = 0;i < 3;i++) {
				ss >> c1;
				output += c1;
			}
			int count = 0;
			if (output == "001")
				count = 1;
			else if (output == "010")
				count = 2;
			else if (output =="011")
				count = 3;
			else if (output == "100")
				count = 4;
			else if (output == "101")
				count = 5;
			else if (output == "110")
				count = 6;
			else if (output == "111")
				count = 7;

			for (int i = 0;i < count +1;i++) {
				decomp.push_back(decomp[decomp.size() - 1]);
			}
		}
		else if (operation == "010") {
			string strloc;
			int loc;
			string bitmask;
			string dict_ind;
			string dict_val;
			output = "";
			for (int i = 0;i < 5;i++) {
				ss >> c1;
				output += c1;
			}
			strloc = output;
			loc = index_conv(strloc);

			output = "";
			for (int i = 0;i < 4;i++) {
				ss >> c1;
				output += c1;
			}
			bitmask = output;
			output = "";
			for (int i = 0;i < 4;i++) {
				ss >> c1;
				output += c1;
			}
			dict_ind = output;
			dict_val = get_dict(dict_ind,ref_dict);
			for (int i = loc;i < loc + 4;i++)
			{
				if (bitmask[i - loc] == '1')
				{
					if (dict_val[i] == '0')
					{
						dict_val[i] = '1';
					}
					else {
						dict_val[i] = '0';
					}
				}
			}
			decomp.push_back(dict_val);
		}
		else if (operation == "011") {
			string strloc;
			int loc;
			string dict_ind;
			string dict_val;
			output = "";
			for (int i = 0;i < 5;i++) {
				ss >> c1;
				output += c1;
			}
			strloc = output;
			loc = index_conv(strloc);
			output = "";
			for (int i = 0;i < 4;i++) {
				ss >> c1;
				output += c1;
			}
			dict_ind = output;
			dict_val = get_dict(dict_ind,ref_dict);
			if (dict_val[loc] == '1')
				dict_val[loc] = '0';
			else
				dict_val[loc] = '1';

			decomp.push_back(dict_val);
		}
		else if (operation == "100") {
			string strloc;
			int loc;
			string dict_ind;
			string dict_val;
			output = "";
			for (int i = 0;i < 5;i++) {
				ss >> c1;
				output += c1;
			}
			strloc = output;
			loc = index_conv(strloc);
			output = "";
			for (int i = 0;i < 4;i++) {
				ss >> c1;
				output += c1;
			}
			dict_ind = output;
			dict_val = get_dict(dict_ind,ref_dict);
			for (int i = 0;i < 2;i++) {
				if (dict_val[loc+i] == '1')
					dict_val[loc+i] = '0';
				else
					dict_val[loc+i] = '1';

			}
			
			decomp.push_back(dict_val);
		}
		else if (operation == "101") {
			string strloc;
			int loc;
			string dict_ind;
			string dict_val;
			output = "";
			for (int i = 0;i < 5;i++) {
				ss >> c1;
				output += c1;
			}
			strloc = output;
			loc = index_conv(strloc);
			output = "";
			for (int i = 0;i < 4;i++) {
				ss >> c1;
				output += c1;
			}
			dict_ind = output;
			dict_val = get_dict(dict_ind,ref_dict);
			for (int i = 0;i < 4;i++) {
				if (dict_val[loc + i] == '1')
					dict_val[loc + i] = '0';
				else
					dict_val[loc + i] = '1';

			}

			decomp.push_back(dict_val);
		}
		else if (operation == "110") {
			string strloc1;
			int loc1;
			string strloc2;
			int loc2;
			string dict_ind;
			string dict_val;
			output = "";
			for (int i = 0;i < 5;i++) {
				ss >> c1;
				output += c1;
			}
			strloc1 = output;
			loc1 = index_conv(strloc1);
			output = "";
			for (int i = 0;i < 5;i++) {
				ss >> c1;
				output += c1;
			}
			strloc2 = output;
			loc2 = index_conv(strloc2);
			output = "";
			for (int i = 0;i < 4;i++) {
				ss >> c1;
				output += c1;
			}
			dict_ind = output;
			dict_val = get_dict(dict_ind,ref_dict);
			if (dict_val[loc1] == '1')
				dict_val[loc1] = '0';
			else
				dict_val[loc1] = '1';
			if (dict_val[loc2] == '1')
				dict_val[loc2] = '0';
			else
				dict_val[loc2] = '1';

			decomp.push_back(dict_val);

		}
		else if (operation == "111") {
			string dict_val;
			string dict_ind;
			output = "";
			for (int i = 0;i < 4;i++) {
				ss >> c1;
				output += c1;
			}
			dict_ind = output;
			dict_val = get_dict(dict_ind,ref_dict);
			decomp.push_back(dict_val);
		}
	}
	return;
}

void write_decomp(vector<string> &decomp) {
	ofstream file;
	file.open("dout.txt");
	for (int i = 0;i < decomp.size()-1;i++)
	{
		file << decomp[i];
		file << endl;

	}
	file.close();
}

int main(int argc, char* argv[])
{
	vector<string> directory;
	vector<int> freq;
	vector<string> instructions;
	vector<string> decomp;
	string binary;
	string final_dict[16];
	string ref_dict[16];
	string comp_binary;

	if (atoi(argv[1]) == 1) {
		init(directory, freq, instructions);
		sort_dict(directory, freq, final_dict);
		binary = compress(instructions, final_dict);
		write_comp(binary, final_dict);
	}
	else if (atoi(argv[1]) == 2) {
		read_comp(comp_binary, ref_dict);
		decompress(comp_binary, ref_dict, decomp);
		write_decomp(decomp);
	}

    return 0;
}

