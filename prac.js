var arr = [8, 9, 19, 3, 2, 5];

var str = "it's wednesday my doods";

// console.log();


/* Array functions
arr.push(val);         - returns the new size if needed
arr.pop();             - also returns the element that was popped
arr.concat(secondArr); - returns the new array
arr.shift();           - takes off the first element and returns the element that was removed
arr.unshift(val);      - push but for front
arr.sort();
arr[i];                 - access operator
arr.find(function);     - finds the first element that satisfies the function 
arr.slice(i, j);        - returns a new copy of array from i to j (non-inclusive)
arr.splice(i, #);       - removes # of elements from i index
arr.reverse();          
arr.map(function);       
*/
function square(a){ return a*a; }


function bigger10(a){ return a > 10; }

function printArray(arr){
    for(var i = 0; i < arr.length; i++){
        console.log(arr[i]);
    }
    return;
}

/* String functions
str.length;
str.search(string)          - re
str.split(char)             - tokenize string based on char
str[i]                      - returns char at index
str.indexOf(string)         - returns index if found, -1 if not present
str.slice(i, j)             - returns substring from i (inclusive) to j (non inclusive)
str.toLowerCase();
str.toUpperCase();

*/

function removeChar(str, c){
    str[0];

}

function tokenize(str){
    return arr;
}