var addOneToBinary = function (number) {
  let i = number.length - 1;
  while (i >= 0 && number[i] === "1") {
    number = number.slice(0, i) + "0" + number.slice(i + 1);
    i--;
  }
  if (i >= 0) {
    number = number.slice(0, i) + "1" + number.slice(i + 1);
  } else {
    number = "1" + number;
  }
  return number;
};

var numSteps = function (number) {
  var count = 0;
  // console.log(addOneToBinary("1011"));
  while (number.length > 1) {
    if (number[number.length - 1] == "1") number = addOneToBinary(number);
    else number = number.slice(0, -1);
    count++;
  }
  return count;
};
