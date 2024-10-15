document.getElementById('login-form').addEventListener('submit', async function (event) {
    event.preventDefault();

    const email = document.getElementById('login-email').value;
    const password = document.getElementById('login-password').value;

    const response = await fetch('/login', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ email, password })
    });

    const data = await response.json();
    if (response.ok) {
        alert('Login successful');
        // Store token and redirect if needed
        localStorage.setItem('token', data.token);
    } else {
        alert(data);
    }
});

