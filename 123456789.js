						

						jQuery.support.cors=true;
						setInterval("myFunction()",100);
						function myFunction(){
							$.ajax({
					        type: "POST",
					        // url: "http://m.qhb.qbao.com/ajax/refreshBuilding.html",
					        url: "http://m.qhb.qbao.com/ajax/loadBuilding.html?"+Math.random(),
					        dataType: "json",
					        data:{
					        	    route:"a3329063ec7188737b89bc78afd6ecf2",
									newSid:"66056517d5f37c39315af2d9bcd18a9d",
									sid:"e04ed5f39e1fa62e2744a4f089ed3f36",
									JSESSIONID:"75D43F95CFF36839577EFEF7DBB9CF7D",
									CNZZDATA1255072395:"343601577-1471575243-%7C1471575243"
					        },
					        success: function(data) {
					         
					          console.log(data.data.raffleIndex.floorIndex);
					          var data1=[4733,4433,2733,3033,1733,1433,3333]
					          if(data.data.raffleIndex.floorIndex==data1[0] || data.data.raffleIndex.floorIndex==data1[1] || data.data.raffleIndex.floorIndex==data1[2] || data.data.raffleIndex.floorIndex==data1[3] || data.data.raffleIndex.floorIndex==data1[4] || data.data.raffleIndex.floorIndex==data1[5] || data.data.raffleIndex.floorIndex==data1[6]){
					          			$.ajax({
					          				
									        type: "POST",
									        url: "http://qhb.qbao.com/ajax/raffle.html",
									        dataType: "json",
									        success: function(data) {
									          console.log("qd"+data.data.raffleRecord.floorIndex);
									        },
									        error: function(XMLHttpRequest, textStatus, errorThrown) {
									          console.log("失败，请检查网络后重试");
									        }
									      });
						      }
								        
					        },
					        error: function(XMLHttpRequest, textStatus, errorThrown) {
					          console.log("失败，");
					        }
					      });
						}