$(document).ready(function () {
    var num=[0,0,0,0,0];
    for (var i = 1; i <=4; i*=2){
        num[i] = parseInt(Math.random() * 15 + 1);
        while (num[i] === num[i/2] || num[i] === num[i/4]) num[i] = parseInt(Math.random() * 16 + 1);
        console.log(num[i] === num[i / 2] || num[i] === num[i / 4]);
        console.log(num[1],num[2],num[4]);
        $("#s" + i).css("background-image", "url(img/smallPhoto-" + num[i] + ".jpg");
    }
});