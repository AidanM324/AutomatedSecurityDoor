// To create literal strings stored in flash memory enclose your HTML code between 
// F(R"=====( HTML code here )=====");
// If you have 1 reading then you probably have 2 literal strings


String homePagePart1 = F(R"=====(<!DOCTYPE html>
<html lang="en" > 
<head>

  <meta charset="utf-8">
  
  <meta name="viewport" content="width=device-width, initial-scale=1, viewport-fit=cover">
 

<title> DHT11 Livefeed </title>
<style>
   
   <!--choose good contrast between background and foreground colours -->
   body {       
	background-color: navy;
  font-family: Arial, Helvetica, sans-serif;
  box-sizing: border-box;
	}

  .main2-div{
      width: 100%;
      margin-bottom: 10px;
      margin-top: 10px;
      background-color: navy;
      }

  .textarea-div{
      width: 100%;
      min-height: 80px;
      line-height: 80px;
      text-align: center;
      margin-bottom: 10px;
      font-style: initial;
      }

  .BoxDHT1-div{
      width: 20%;
      min-height: 400px;
      line-height: 70px;
      text-align: center;
      margin-left: 10%;
      float: left;
      border-radius: 10%;
      border: 1px solid black;
      height: 470px;
      background-color: DodgerBlue;
      }

    .BoxDHT2-div{
      width: 50%;
      min-height: 400px;
      line-height: 70px;
      
      margin-left: 5%;
      float: left;
      border-radius: 10%;
      height: 470px;
      border: 1px solid black;
      display: flex;
      flex-direction: column;
      background-color: DodgerBlue;
      align-items: center;
      } 

  th, td {
    font-size: 25px;
    padding: 8px;
    text-align: left;
    border-bottom: 1px solid #ddd;
}
</style>
</head>
	<body>
		<div class="main2-div" class="clearfix">
        <div class="BoxDHT1-div"> 
            <h3>Welcome, User! </h3>

            <p>This is the Livefeed Portal<hr>for Access Room Temperature<br>Using the DHT11 Compontent</p>
        </div>

        <div class="BoxDHT2-div">
		<h1> - DHT11 Livefeed - </h1>
      
		<p>Temperature Of Access Room</p>
    
		<table>
        <tr>
          <th>Sensor</th>
          <th>Value</th>
          <th>Unit</th>
        </tr>
        <tr>
          <td>Temperature</td>
          <td> )=====");
String homePagePart2 = F(R"=====(</td>
         <td>Degree Cel</td>
        </tr>
      </table>
     </div>
	</body>
</html>)=====");
