import React from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import Home from './components/Home';
import Result from './components/Result';
import './App.css';

const App = () => {
    return (
        <Router>
            <div className="App">
                <Routes>
                    <Route path="/" element={<Home />} />
                    <Route path="/result" element={<Result />} />
                </Routes>
            </div>
        </Router>
    );
};

export default App;
