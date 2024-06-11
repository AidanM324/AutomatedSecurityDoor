String MainPagePart1 = F(R"=====(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Automated Security</title>

<style>
    body{
    font-family: Arial, Helvetica, sans-serif;
    box-sizing: border-box;
    background-color: beige;
}

.main1-div{
    width: 100%;
    margin-bottom: 10px;
}

.logo-div{
    width: 100%;
    min-height:50px;
   
    text-align: left;
    margin-left: 20px;
}

.intro-div{
    width: 50%;
    min-height:50px;
    line-height:40px;
    text-align: left;
    color: black;
    font: bolder;
    margin-left: 20px;
    float: left;
}

.header-div{
    width: 50%;
    line-height:25px;
    text-align: left;
    margin-top: 100px;
    margin-left: 20px;
    margin-bottom: 5px;
    float: left;
}

.tools{
    color: purple;
}

.image-div{
    width: 40%;
    float: right;
    min-height: 50px;
    margin-bottom: 40px;
    margin-top: 60px;
    line-height: 10px;
}

.textarea-div{
    width: 100%;
    min-height: 80px;
    line-height:80px;
    text-align: center;
    margin-bottom: 10px;
    font-style: initial;
    background-color: wheat;
}

.main2-div{
    width: 100%;
    margin-bottom: 10px;
    margin-top: 10px;
    background-color: wheat;
}

.Box1-div{
    width: 40%;
    min-height: 400px;
    line-height: 70px;
    text-align: center;
    
    float: right;
    border-radius: 10%;
    margin-left: 5%;
    height: 470px;
}

.Box2-div{
    width: 40%;
    min-height: 400px;
    line-height: 70px;
    text-align: center;
    
    float: right;
    margin-left: 5%;
    margin-right: 5%;
    border-radius: 10%;
    height: 470px;
} 

.clearfix::after{
    content:"";
    display:block;
    clear:both;
}

.footer-div{
    width: 100%;
    min-height: 50px;
    line-height: 50px;
    font-size: smaller;
}

img {
    border-radius: 20%;
}

.curve{
    border-radius: 20px; 
    padding: 10px; 
    font-size: 14px;
    color: purple;
}
    </style>

     <script>
        function checkPasswordRFID() {
            
            var password = document.getElementById("password").value;

        
            if (password === "rfid") {
                
                window.location.href = "RFID.html" ;
            } else {
                alert("Incorrect password. Please try again.");
            }
        }
    </script>

<script>
    function checkAdminPassword1() {
        // Get the password entered by the user
        var password = document.getElementById("admin").value;

        // Check if the password is correct 
        if (password === "admin") {
            // Redirect to another page if the password is correct
            window.location.href = "/admin" ;
        } else {
            // Display an error message if the password is incorrect
            alert("Incorrect Admin password. Please try again.");
        }
    }
</script>

<script>
    function checkCredentials() {
    
        var storedEmails = JSON.parse(localStorage.getItem("userEmails")) || [];
        var storedPasswords = JSON.parse(localStorage.getItem("userPasswords")) || [];
        var enteredEmail = document.getElementById("email").value;
        var enteredPassword = document.getElementById("password").value;

        if (storedEmails.includes(enteredEmail) && storedPasswords.includes(enteredPassword)) {
            window.location.href = "/DHT11";
        } else {
            alert("Invalid email or password. Please try again.");
        }
    }
</script>

</head>
<body>
    <br>
    <div class="logo-div">
        <h3> Aidan Malone </h3> 
        <h5>Atlantic Technological University</h5>
    </div>
        <hr>
    <div class="main1-div" class="clearfix">

        <div class="intro-div"><h5 class="tools"> THE NEW TOOLS </h5>
            <h1>Automated<br>Security<br>Door<br><br></h1>
            
        </div>
        
        <div class="header-div">
            <p>This is the access page for my IOT Automated Security Door
            <br>Password and Login details required, new RFID tag issued to new sign ups.
            <hr>
            <br>

            <h3><b><i><u>List of Operations</u></i></b></h3>

            <ul class="tools" type="square">
                <br>
                <li>User Login</li>
                <br>
                <li>User Sign Up</li>
                <br>
                <li>DHT11 Access</li>
                <br>
                <li>RFID Tag Issue</li>
                <br>
            
            </ul>
</div>

    </div>
    
    
    <div class="main2-div" class="clearfix">
        <div class="Box1-div"> 
            <h1 style="font-family: 'Calibri'"><u>Options</u></h1>
            <h4> Enter Password Here to gain access to DHT11 Livefeed </h4>
            <form>
                <label for="email">Email : </label>
                <input type="email" class="curve" id="email" required>
                <br>
                <label for="password">Password:</label>
                <input type="password" class="curve" id="password" required>
                <br>
                <input type="button" class="curve" value="Submit"  onclick="checkCredentials()">
            </form>
        </div>

        <div class="Box2-div">
        <h1 style="font-family: 'Calibri'"><u>Admin</u></h1>
            <h4>Sign Up.</h4>
            <form>
                <label for="password">Enter Password:</label>
                <input type="password" class="curve" id="admin" name="admin" required>
                <br>
                <input type="button" class="curve" value="Submit" onclick="checkAdminPassword1()">
            </form>
            <hr>
            <hr>
            <h5>RFID Tag Registor.</h5>
            <form>
                <label for="password">Enter Password:</label>
                <input type="password" class="curve" id="rfid" name="rfid" required>
                <br>
                <input type="button" class="curve" value="Submit" onclick="checkPasswordRFID()">
            </form>
            <p style="font-size: 10px;">note: accounts must be created before login can occur. </p>
        </div>

    </div>
    

   
</body>
</html> )=====");