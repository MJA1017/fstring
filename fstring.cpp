#include <bits/stdc++.h>

using namespace std;

// var x = 10;
//var name = "ten"
// print("my {x} is {name}");

//output : my 10 is ten

bool does_exist(const vector< vector<string> >&  v, string item){

     vector< vector<string> >::const_iterator row;

    for (row = v.begin(); row != v.end(); row++) {
        if(find(row->begin(), row->end(), item) != row->end() )
            return true;
    }

    return false;
}

int main()
{

    ifstream file("input.txt");
    string line;
    
    vector<vector<string>> variables = {};
    while (getline(file, line))
    {
        // process string ...
        

        //removing the print("") if it is a print line
        if(line.substr(0,6) == "print("){

            int counter, start_pos, end_pos;
            string val = "";
            

            line.erase(line.size() - 1);
            line.erase(line.size() - 1);
            line = line.substr(7);
            
            
            

            for(int i=0;i<line.length();i++){

                string variable_name = "";

                if(line[i] == '{'){



                    start_pos = i;
                    counter = i+1;

                    while(line[counter] != '}'){
                        variable_name+=line[counter];
                        counter++;  
                    }
                    end_pos = counter;


                    if(does_exist(variables,variable_name)){

                        for(int j=0;j<variables.size();j++){
                            if(variables[j][0] == variable_name){
                                val = variables[j][1];
                            }
                        }

                        string first = line.substr(0,start_pos);
                        string second = line.substr(end_pos+1);

                        line = first + val + second;
                        
                    }
                    else{
                        cout<<"ERROR! Variable " + variable_name + " is not found"<<endl;
                        return 0;
                    }
                    
                }

                
            }

            cout<<line<<endl;
        }
    
        //var x = 10
        

        else if(line.substr(0,4) == "var "){

            int counter = 0;
            string var = "";
            string val = "";
            counter = 4;
            
            
            while(line[counter] != ' '){
                var+=line[counter];
                counter++;
            }
            
            

            counter++;
            if(line[counter] == '=' && line[counter+1] == ' '){
                
                counter += 2;
                while(line[counter] != ';'){
                    val+=line[counter];
                    counter++;
                }
                
            }
            
            variables.push_back({var,val});
        }

        else{
            continue;
        }
    }

    // for(int i=0;i<variables.size();i++){
    //     cout<<variables[i][0]<<" "<<variables[i][1]<<endl;
    // }

    return 0;
}