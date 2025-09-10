#include <bits/stdc++.h>
using namespace std;
/*
690. Employee Importance
You have a data structure of employee information, including the employee's unique ID, importance value, and direct subordinates' IDs.

You are given an array of employees employees where:

employees[i].id is the ID of the ith employee.
employees[i].importance is the importance value of the ith employee.
employees[i].subordinates is a list of the IDs of the direct subordinates of the ith employee.
Given an integer id that represents an employee's ID, return the total importance value of this employee and all their direct and indirect subordinates.


*/
// DFS 
void dfs(int id, vector<Employee*> employees,int &totalImpValue, unordered_map<int, Employee*>&mp){
    if(id<1) return ;
    Employee* e = mp[id];
    totalImpValue+=e->importance;
    for(int sub: e->subordinates){
        dfs(sub,employees,totalImpValue,mp);
    }
}
int getImportance(vector<Employee*> employees, int id) {
    int totalImpValue=0;
    unordered_map<int, Employee*>mp;
    for(auto e:employees){
        mp[e->id] = e;
    }
    dfs(id, employees, totalImpValue,mp);
    return totalImpValue;
}
// BFS
void bfs(int id, vector<Employee*> employees,int &totalImpValue, unordered_map<int, Employee*>&mp){
    queue<int>Q;
    Q.push(id);
    while(!Q.empty()){
        int curr = Q.front(); Q.pop();
        Employee* e = mp[curr];
        totalImpValue+=e->importance;
        for(int sub: e->subordinates){
            Q.push(sub);
        }
    } 
}
int getImportance(vector<Employee*> employees, int id) {
    int totalImpValue=0;
    unordered_map<int, Employee*>mp;
    for(auto e:employees){
        mp[e->id] = e;
    }
    bfs(id, employees, totalImpValue,mp);
    return totalImpValue;
}