/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    if(s[0] === ")" || s[0] === "]" || s[0] === "}")
        return false;
    
    let arr = [], res = true;
    
    s.split("").forEach(char => {
        if(char === "(" || char === "{" || char === "[")
        {
            arr.push(char)
        }
        else
        {
            const temp = arr.pop();
            if(char === ")" && temp !== "(")
            {
                res = false;
                return;
            }
            if(char === "]" && temp !== "[")
            {
                res = false;
                return;
            }
            if(char === "}" && temp !== "{")
            {
                res = false;
                return;
            }
        }
    });
    
    return res && arr.length === 0;
};