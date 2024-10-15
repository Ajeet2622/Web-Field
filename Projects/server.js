const express = require('express');
const mongoose = require('mongoose');
const bcrypt = require('bcryptjs');
const bodyParser = require('body-parser');
const jwt = require('jsonwebtoken');

dotenv.config(); // Load environment variables

const app = express();
app.use(bodyParser.json());

mongoose.connect(process.env.MONGO_URI, { useNewUrlParser: true, useUnifiedTopology: true })
    .then(() => console.log('MongoDB connected'))
    .catch(err => console.log(err));



// Create express app
// const app = express();
// app.use(bodyParser.json());

// MongoDB connection string
const mongoURI = 'your-mongo-connection-string';
mongoose.connect(mongoURI, { useNewUrlParser: true, useUnifiedTopology: true })
    .then(() => console.log('MongoDB connected'))
    .catch(err => console.log(err));

// User Schema
const UserSchema = new mongoose.Schema({
    name: String,
    email: { type: String, unique: true },
    password: String,
});

const User = mongoose.model('User', UserSchema);

// Route for User Signup
app.post('/signup', async (req, res) => {
    const { name, email, password } = req.body;

    // Check if user already exists
    let user = await User.findOne({ email });
    if (user) {
        return res.status(400).send('User already exists');
    }

    // Hash password
    const hashedPassword = await bcrypt.hash(password, 10);

    // Create new user
    user = new User({ name, email, password: hashedPassword });
    await user.save();

    res.status(201).send('User registered');
});

// Route for User Login
app.post('/login', async (req, res) => {
    const { email, password } = req.body;

    // Check if user exists
    const user = await User.findOne({ email });
    if (!user) {
        return res.status(400).send('Invalid credentials');
    }

    // Compare passwords
    const isMatch = await bcrypt.compare(password, user.password);
    if (!isMatch) {
        return res.status(400).send('Invalid credentials');
    }

    // Generate JWT token
    const token = jwt.sign({ userId: user._id }, 'secretkey', { expiresIn: '1h' });
    res.json({ token });
});

// Start the server
app.listen(5000, () => {
    console.log('Server is running on port 5000');
});


