$(document).ready(function(){
    
    tryMyCookieCookie = window.localStorage;

    $('#forgotten').on('click', function(){
        alert('   Too bad \n ¯\\_(•_•)_/¯');
    })

    $('div.options').on('click', '.SI', function(){
        $('div.Sign-Up').remove();
        $('div.Sign-In').remove();
        $('.central').append(`
        <div class='Sign-In'>
            <form id='info'>
                <input id="email" type="email" placeholder="Email" required>
                <br />
                <br />
                <input id="pass" type="password" maxlength='8' pattern='[A-Za-z0-9]+' placeholder="Password" required>
                <button type='button' class='go'>Sign In</button>
                <a id='forgotten'>Forgot your password?</a>
            </form>
        </div>        
        `);
    })

    $('div.options').on('click', '.SU', function(){
        $('div.Sign-In').remove();
        $('div.Sign-Up').remove();
        $('.central').append(`
        <div class='Sign-Up'>
            <form id='info' name="signup">
                <input id="user" type="text" name="username" placeholder="User" required>
                <br />
                <br />
                <input id="pass" type="password" name="passwd" maxlength='8' pattern='[A-Za-z0-9]+' placeholder="Password" required>
                <br />
                <br />
                <div class='name'>
                    <div><input type="text" placeholder="Name" name="firstname" id='name'></div>
                    </t>
                    <div><input type="text" placeholder="Last name" name="lastname" id='lastName' required></div>
                </div>
                <br />
                <input id="email" type="email" name="mail" placeholder="Email" required>
                <br />
                <br />
                <input id="birth" type="date" name="birthdate" placeholder="Your birth date" required>
                <br />
                <br />
                <select id='interest'>
                    <option value="" selected>Please choose your interest... (optional)</option>
                    <option value='Being organized'>Being organized</option>
                    <option value='Computer Science'>Computer Science</option>
                    <option value='Movies'>Movies</option>
                    <option value='Work' disabled>Work</option>
                    <option value='Nothing'>Nothing at all</option>
                </select>
                <br />
                <br />
                <select id='language'>
                    <option value="" selected>Please choose your language... (optional)</option>
                    <option value='Spanish' disabled>Spanish</option>
                    <option value='Chinese' disabled>Chinese</option>
                    <option value='English' disabled>English</option>
                    <option value='Esperanto'>Esperanto</option>
                    <option value='Russian' disabled>Russian</option>
                </select>
                <br />
                <br />
                <textarea id='motivation' name="objective" cols="40" rows="2" placeholder='What do you plan to use the site for? (optional)'></textarea>
                <br />
                <br />
                <div class='checked'>
                    <input id="check" name='check' type="checkbox" value='accepted' required> 
                    <label for='check'>Confirm you haven't read our terms and conditions</label>
                </div>
                <div class='buttons'>
                    <button type="reset" class="cancel">Cancel</button>
                    <button type="button" class="confirm"><strong>Sign Up</strong></button>
                </div>
            </form>
        </div>        
        `);
    })

    $('.central').on('click', '.confirm', function(){
        if(localStorage.getItem('email') != $('#email').val()){
            localStorage.setItem('user', $('#user').val());
            localStorage.setItem('pass', $('#pass').val());
            localStorage.setItem('name', $('#name').val());
            localStorage.setItem('lastName', $('#lastName').val());
            localStorage.setItem('email', $('#email').val());
            localStorage.setItem('birth', $('#birth').val());
            localStorage.setItem('interest', $('#interest').val());
            localStorage.setItem('language', $('#language').val());
            localStorage.setItem('motivation', $('#motivation').val());
            jump();
        }else{
            alert('There is already an account with the current email');
        }
    })

    $('.central').on('click', '.go', function(){
        if(localStorage.getItem('email') == $('#email').val() && localStorage.getItem('pass') == $('#pass').val()){
            jump();
        }else{
            alert('Email or Password incorrects');
        }
    })

    function jump(){
        window.open('index.html', '_self');
    }
    

    $("form[name='signup']").validate({
        // Specify validation rules
        rules: {
            // The key name on the left side is the name attribute
            // of an input field. Validation rules are defined
            // on the right side
            username: "required",
            firstname: "required",
            lastname: "required",
            mail: {
            required: true,
            // Specify that email should be validated
            // by the built-in "email" rule
            email: true
            },
            password: {
            required: true,
            minlength: 5
            }
        },
        // Specify validation error messages
        messages: {
            username: "Please enter your user name",
            firstname: "Please enter your firstname",
            lastname: "Please enter your lastname",
            password: {
            required: "Please provide a password",
            minlength: "Your password must be at least 5 characters long"
            },
            mail: "Please enter a valid email address"
        },
        // Make sure the form is submitted to the destination defined
        // in the "action" attribute of the form when valid
        submitHandler: function(form) {
            form.submit();
        }
  });

});
