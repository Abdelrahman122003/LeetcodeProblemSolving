/**
 * @param {string} s
 * @param {string} t
 * @param {number} maxCost
 * @return {number}
 */
var equalSubstring = function (s, t, maxCost) {
  var start = 0,
    cost = 0,
    ans = 0;
  for (let i = 0; i < s.length; i++) {
    cost += Math.abs(s.charCodeAt(i) - t.charCodeAt(i));
    while (cost > maxCost) {
      cost -= Math.abs(s.charCodeAt(start) - t.charCodeAt(start));
      start++;
    }
    ans = Math.max(ans, i - start + 1);
  }
  return ans;
};
