//www.880910.com/?login
//www.888fy.com/lottery_cqssc.php



var flag_arr = [-1];
var bei = 50;
var data_result_last3 = [2, 1, 8, 9, 4];
var data_result_last4 = [0, 0, 0, 0, 0];


var flags = false;
var code_pre;
myFunction100();

function myFunction100() {
    // 获取历史数据开始
    $.ajax({
        type: "POST",
        url: "http://www.888fy.com/?controller=default&action=main",
        dataType: "json",
        data: {
            lotteryid: "1",
            flag: "getprizeandcode"
        },
        success: function(data) {
            console.log("jieguo" + data.code[0].issue + data.code[0].code);
            code_pre = data.code[0].code;
            touzhu_queding(data);

            $("#right_05").find("div").eq(0).find(".btnList").find("li").eq(5).click(); //清除zhe一行
            console.log(data_result_last4);
            touzhu(data_result_last4[0], data_result_last4[1], data_result_last4[2], data_result_last4[3], data_result_last4[4]);
            $("#lt_sendok").click();

            setTimeout("myFunction0()", 5000);
            setTimeout("myFunction1()", 10000);
        },
        error: function(XMLHttpRequest, textStatus, errorThrown) {
            console.log("失败，请检查网络后重试");
        }
    });
    // 获取历史数据结束
}



// 处理数据筛选出data_result_last3开始
// var data_result_last3 = [2,4,0,3,7];  
var touzhu_queding = function(data) {

        var data_result = [0];
        var data_result_last2 = [];

        for (var i = 0; i < 10; i++) {
            data_result[i] = data.code[i].code.substring(0, 1);
        }

        console.log(data_result);

        for (var i = 0; i < 10; i++) {
            var flag_same = 0;
            for (var j = 0; j < data_result_last2.length; j++) {
                if (data_result[i] == data_result_last2[j]) {
                    flag_same = 1;
                    break;
                } else {
                    continue;
                }
            }

            if (!flag_same && data_result_last2.length < 5) {
                data_result_last2.push(data_result[i]);
            }



        }

        console.log("data_result_last2中间=" + data_result_last2);

        if (data_result_last2.length == 1) {
            for (var p = 0; p < 4; p++) {
                data_result_last2.push(data_result_last3[p]);
            }

        } else if (data_result_last2.length == 2) {
            for (var p = 0; p < 3; p++) {
                data_result_last2.push(data_result_last3[p]);
            }

        } else if (data_result_last2.length == 3) {
            for (var p = 0; p < 2; p++) {
                data_result_last2.push(data_result_last3[p]);
            }

        } else if (data_result_last2.length == 4) {
            for (var p = 0; p < 1; p++) {
                data_result_last2.push(data_result_last3[p]);
            }

        } else if (data_result_last2.length == 5) {

        }

        console.log("data_result_last3之前=" + data_result_last3);
        data_result_last3 = data_result_last2;

        var b = 0;
        console.log("data_result_last4之前=" + data_result_last4);

        for (var a = 0; a < 10; a++) {
            if (!contains(data_result_last3, a)) {
                data_result_last4[b++] = a;
            }

        }


        console.log("data_result_last3之后=" + data_result_last3);
        console.log("data_result_last2=" + data_result_last2);
        console.log("data_result_last4之后=" + data_result_last4);

    }
    // 处理数据筛选出data_result_last3结束



// 选择制定号码函数开始
var touzhu = function(one, two, three, four, five) {
        // var result=[];
        $("#right_05").find("div").eq(0).find(".numList").find("li").eq(one).click();
        $("#right_05").find("div").eq(0).find(".numList").find("li").eq(two).click();
        $("#right_05").find("div").eq(0).find(".numList").find("li").eq(three).click();
        $("#right_05").find("div").eq(0).find(".numList").find("li").eq(four).click();
        $("#right_05").find("div").eq(0).find(".numList").find("li").eq(five).click();


        $("#moneyModle").find("label").eq(2).click(); //分模式
        $("#lt_sel_times").val(bei); //50倍
        $("#lt_sel_insert").click(); //添加号码
        $("#right_05").find("div").eq(0).find(".btnList").find("li").eq(5).click(); //清除zhe一行

    }
    // 选择制定号码函数结束


// 定时确认投注函数开始
var myFunction0 = function() {
    $('#confirm_yes', parent.document).click();
}

var myFunction1 = function() {
        $('#alert_close_button', parent.document).click();
    }
    // 定时确认投注函数结束

// js判断一个数是否在数组中开始
var contains = function(arr, obj) {
        var t = arr.length;
        while (t--) {
            if (arr[t] == obj) {
                return true;
            }
        }
        return false;
    }
    // js判断一个数是否在数组中结束



function myFunction1000() {
    // 获取历史数据开始
    $.ajax({
        type: "POST",
        url: "http://www.888fy.com/?controller=default&action=main",
        dataType: "json",
        data: {
            lotteryid: "1",
            flag: "getprizeandcode"
        },
        success: function(data) {
            console.log("jieguo" + data.code[0].issue + data.code[0].code);
            flags = (data.code[0].code == code_pre);
            console.log("flags=" + flags);
            // 测试
            // flags=false;
            //判断当前是否中
            if (!flags) {
                var flag_arr_current = -1;

                for (var m = 0; m < data_result_last4.length; m++) {

                    if (data.code[0].code.substring(0, 1) == data_result_last4[m]) {
                        flag_arr_current = 1;
                        break;
                    } else {
                        continue;
                    }
                }


                if (flag_arr_current == 1 && flag_arr.length < 10) {
                    flag_arr.push(1);
                } else if (flag_arr_current == -1 && flag_arr.length < 10) {
                    flag_arr.push(-1);
                } else if (flag_arr.length == 10) {
                    flag_arr = [];
                    flag_arr.push(flag_arr_current);

                }

                if (flag_arr.length == 10) {
                    // flag_arr.push(-1);
                    var sum = 0;
                    for (var q = 0; q < 10; q++) {
                        sum += flag_arr[q];
                    }

                    if (sum <= -4) {
                        if (bei == 50) {
                            bei = 100;
                        } else if (bei == 100) {
                            bei = 150;
                        }
                    } else if (sum >= 2) {
                        if (bei == 100) {
                            bei = 50;
                        } else if (bei == 150) {
                            bei = 100;
                        }
                    }
                    // console.log(bei);
                }

                console.log("flag_arr=" + flag_arr);

            }

            if (!flags) {
                myFunction100();
            }
        },
        error: function(XMLHttpRequest, textStatus, errorThrown) {
            console.log("失败，请检查网络后重试");
        }
    });
    // 获取历史数据结束
}
setInterval("myFunction1000()", 60000);
