document.addEventListener("DOMContentLoaded", function() {
    const bookNowBtn = document.getElementById('btn-cta');
    
    bookNowBtn.addEventListener('click', function(e) {
        e.preventDefault(); // Prevent default link behavior

        // Redirect to the login page
        window.location.href = 'Projects/Html/Login and signUp.html'; // Replace with the actual login page URL
    });
});
