/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumber = function (nums) {
  let m = new Map();
  for (let k of nums) {
    if (m.has(k)) m.set(k, m.get(k) + 1);
    else m.set(k, 1);
  }
  let ans = [];
  for (let [k, v] of m) if (v === 1) ans.push(k);
  return ans;
};
