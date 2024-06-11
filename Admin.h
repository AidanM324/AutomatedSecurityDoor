String MainAdminPart1 = F(R"=====( <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Admin Sign Up</title>
    
    <style>
     body{
    font-family: Arial, Helvetica, sans-serif;
    box-sizing: border-box;
    background-color: beige;
}

.logo-div{
    width: 100%;
    min-height:50px;
   
    text-align: left;
    margin-left: 20px;
}

.tools{
    color: purple;
}

.adminimage-div{
    width: 40%;
    float: right;
    min-height: 50px;
    
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

.admin-div{
    width: 100%;
    margin-bottom: 10px;
    margin-top: 10px;
}

.BoxAdmin-div{
    width: 50%;
    min-height: 400px;
    line-height: 40px;
    text-align: center;
    float: left;
    margin-left: 5%;
    border-radius: 10%;
    height: 550px;
    border: 1px solid black;
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

</head>
<body>
    <div class="logo-div">
        <h3> Atlantic Technological University </h3> 
    </div>
        <hr>
    
    <div class="textarea-div"> 
        <h1><b>Sign Up</b> Form</h1>
    </div>

    <div class="admin-div" class="clearfix">

        <div class="adminimage-div">
            <img src="admin.png" width="400" height="550" border="1">
        </div>

        <div class="BoxAdmin-div"> 
            <h5 class="tools"> WELCOME </h5>
            <h2 style="font-family: 'Calibri'">  Hello, Friend!<br></h2>
            <br>
            
            <form>
                <label for="name" style="font-family: 'Calibri'" style="color: 'purple'">Name:</label>
                <input type="text" class="curve" id="name" required>
                <br>
                <br>
                <label for="email">Email:</label>
                <input type="email" class="curve" id="email" required>
                <br>
                <br>
                <label for="password" >Password:</label>
                <input type="password" class="curve" id="password" required>
                <br>
                <br>
                <input type="button" class="curve" value="Create Account" onclick="storeUserData()">
            </form>

            <script>
                function storeUserData() {
                    var name = document.getElementById("name").value;
                    var email = document.getElementById("email").value;
                    var password = document.getElementById("password").value;
            
                    // Store the user's email in Local Storage
                   // localStorage.setItem("userEmail", email);
                    //localStorage.setItem("userName", name);

                     // Retrieve existing emails from Local Storage
        var storedEmails = JSON.parse(localStorage.getItem("userEmails")) || [];
        var storedPasswords = JSON.parse(localStorage.getItem("userPasswords")) || [];

// Add the new email to the array
storedEmails.push(email);
storedPasswords.push(password);

// Store the updated array back in Local Storage
localStorage.setItem("userEmails", JSON.stringify(storedEmails));
localStorage.setItem("userPasswords", JSON.stringify(storedPasswords));
            
                    // Redirect the user to the password entry page
                    window.location.href = "/";
                }
            </script>
        </div>
    </div>
<hr>
    <div class="footer-div"> 
        &copy;
    </div>
</body>
</html>  )=====");