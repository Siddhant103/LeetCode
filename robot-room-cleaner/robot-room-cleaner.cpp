/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    void backtrack(Robot& robot){
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    void startCleaning(Robot& robot, int row, int col, int facing, set<pair<int, int>>& cleaned){
        robot.clean();
        cleaned.insert(make_pair(row, col));
        
        vector<vector<int>> directions = {{-1, 0},{0, 1},{1, 0},{0, -1}};
        for(int i=0;i<4;i++){
            vector<int> direction = directions[(facing + i) % 4];
            pair nextPair = make_pair(row + direction[0], col + direction[1]);
            if(cleaned.find(nextPair) == cleaned.end() && robot.move()){
                startCleaning(robot, nextPair.first, nextPair.second, (facing + i) % 4, cleaned);
                backtrack(robot);
            }
            robot.turnRight();
        }
            
    }
    void cleanRoom(Robot& robot) {
        set<pair<int, int>> cleaned;
        startCleaning(robot, 0, 0, 0, cleaned);
    }
};