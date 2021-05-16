/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    int dfs(unordered_map<int, Employee*>& emp, int id){
        int sum = emp[id]->importance;
        
        for(int subs: emp[id]->subordinates){
            sum += dfs(emp, subs);
        }
        
        return sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        
        unordered_map<int, Employee*> emp;
        
        for(auto employee: employees){
            emp.insert({employee->id, employee});
        }
 
        return dfs(emp, id);
    }
};