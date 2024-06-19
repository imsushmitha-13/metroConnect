from flask import Flask, request, render_template # type: ignore
import subprocess
import os

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/process', methods=['POST'])
def process():
    source = request.form['source']
    destination = request.form['destination']

    # Compile the C++ program
    compile_result = subprocess.run(['g++', 'route_program.cpp', '-o', 'route_program'], capture_output=True, text=True)
    if compile_result.returncode != 0:
        return f"Error compiling C++ program: {compile_result.stderr}"

    # Run the compiled C++ program with the source and destination as arguments
    run_result = subprocess.run(['./route_program', source, destination], capture_output=True, text=True)
    
    if run_result.returncode != 0:
        return f"Error running C++ program: {run_result.stderr}"

    # Pass the output to the template
    return render_template('output.html', output=run_result.stdout)

if __name__ == '__main__':
    app.run(debug=True)
