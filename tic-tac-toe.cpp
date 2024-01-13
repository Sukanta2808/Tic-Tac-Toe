#include<bits/stdc++.h>

using namespace std;

void instruction(){
    cout<<"Instructions:"<<endl;
    cout<<"Enter the available position as per tic tac toe box.Please enter available position otherwise the code may break."<<endl;
    cout<<"Player1--> O && Player2--> X"<<endl<<endl;
}

void print(vector<vector<char>>& arr){
    cout<<"   "<<"|"<<"   "<<"|"<<endl;
    cout<<" "<<arr[0][0]<<" | "<<arr[0][1]<<" | "<<arr[0][2]<<endl;
    cout<<"_ _"<<" "<<"_ _"<<" "<<"_ _"<<endl;
    cout<<"   "<<"|"<<"   "<<"|"<<endl;
    cout<<" "<<arr[1][0]<<" | "<<arr[1][1]<<" | "<<arr[1][2]<<endl;
    cout<<"_ _"<<" "<<"_ _"<<" "<<"_ _"<<endl;
    cout<<"   "<<"|"<<"   "<<"|"<<endl;
    cout<<" "<<arr[2][0]<<" | "<<arr[2][1]<<" | "<<arr[2][2]<<endl<<endl;
}

bool check(vector<vector<char>>&arr,char ch){
    if(((arr[0][0]==ch)&&(arr[0][1]==ch)&&(arr[0][2]==ch))||
    ((arr[1][0]==ch)&&(arr[1][1]==ch)&&(arr[1][2]==ch))||
    ((arr[2][0]==ch)&&(arr[2][1]==ch)&&(arr[2][2]==ch))||
    ((arr[0][0]==ch)&&(arr[1][0]==ch)&&(arr[2][0]==ch))||
    ((arr[0][1]==ch)&&(arr[1][1]==ch)&&(arr[2][1]==ch))||
    ((arr[0][2]==ch)&&(arr[1][2]==ch)&&(arr[2][2]==ch))||
    ((arr[0][0]==ch)&&(arr[1][1]==ch)&&(arr[2][2]==ch))||
    ((arr[0][2]==ch)&&(arr[1][1]==ch)&&(arr[2][0]==ch))) return true;
    return false;
}

int main(){
    vector<vector<char>> arr(3,vector<char>(3));
    vector<int> v(9,0);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) arr[i][j]='0'+i*3+j+1;
    }
    print(arr);
    instruction();
    int flag=0,count=0;
    while(true){
        cout<<"Enter position -- Player "<<flag+1<<endl;
        int n;
        cin>>n;
        n--;
        if(n>=0 && n<9 && v[n]==0) v[n]=1;
        else{
            cout<<"Invalid Input.Please give valid position."<<endl;
            continue;
        }
        if(flag==0){
            arr[n/3][n%3]='O';
            print(arr);
            if(check(arr,'O')){
                cout<<"Player1 wins"<<endl;
                break;
            }
            flag=1;
        }
        else{
            arr[n/3][n%3]='X';
            print(arr);
            if(check(arr,'X')){
                cout<<"Player2 wins"<<endl;
                break;
            }            
            flag=0;
        }
        count++;
        if(count==9){
            cout<<"Match draws"<<endl;
            break;
        }
    }
    return 0;
}
