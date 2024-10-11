const switchToSignUp = document.getElementById('switch-to-signup');
const switchToLogin = document.getElementById('switch-to-login');
const loginForm = document.getElementById('login-form');
const signupForm = document.getElementById('signup-form');
const formTitle = document.getElementById('form-title');
const formSwitchText = document.getElementById('form-switch-text');

// Switch to Sign Up form
switchToSignUp.addEventListener('click', (e) => {
    e.preventDefault();
    signupForm.style.display = 'block';
    loginForm.style.display = 'none';
    formTitle.textContent = 'Sign Up';
    formSwitchText.innerHTML = 'Already have an account? <a href="#" id="switch-to-login">Login</a>';
    document.getElementById('switch-to-login').addEventListener('click', switchToLoginForm);
});

// Switch to Login form
function switchToLoginForm(e) {
    e.preventDefault();
    signupForm.style.display = 'none';
    loginForm.style.display = 'block';
    formTitle.textContent = 'Login';
    formSwitchText.innerHTML = 'Don\'t have an account? <a href="#" id="switch-to-signup">Sign Up</a>';
    document.getElementById('switch-to-signup').addEventListener('click', switchToSignUpForm);
}

// Handle sign up form submission
signupForm.addEventListener('submit', function(e) {
    e.preventDefault();

    // Perform validation or API call here
    const name = document.getElementById('signup-name').value;
    const email = document.getElementById('signup-email').value;
    const password = document.getElementById('signup-password').value;
    const confirmPassword = document.getElementById('signup-confirm-password').value;

    if (password === confirmPassword) {
        // Proceed with signup (e.g., send data to server, store in local storage)
        alert('Sign up successful! Redirecting to your dashboard...');

        // Redirect to the dashboard or homepage
        window.location.href = 'Project of pronted\Html\Hotel_management_system.html';  // Replace 'dashboard.html' with your actual page
    } else {
        alert('Passwords do not match!');
    }
});

// Handle login form submission
loginForm.addEventListener('submit', function(e) {
    e.preventDefault();

    // Perform login validation or API call here
    const email = document.getElementById('login-email').value;
    const password = document.getElementById('login-password').value;

    // Simulate login success and redirect to dashboard
    //alert('Login successful! Redirecting to your dashboard...');
    window.location.href = 'Projects\Html\Hotel_management_system.html';  // Replace 'dashboard.html' with your actual page
});
