import json
import requests

def generate_qml_code(prompt):
    """Generates QML code by sending the prompt to the API."""
    url = "http://localhost:11434/api/generate"
    payload = {
        "model": "llama3",
        "prompt": prompt,
        "temperature": 0,
    }
        
    response = requests.post(url, json=payload)
    response.raise_for_status()
    
    return response.content.decode().split("\n")


def parse_response(response_lines):
    """Parses the response lines and extracts the QML code."""
    generated_code = ""
    
    for line in response_lines:
        if not line.strip():
            continue
        try:
            parsed_obj = json.loads(line)
            generated_code += parsed_obj["response"]
        except json.JSONDecodeError as e:
            print(f"Error decoding JSON: {e}")
    
    return generated_code


def generate_qml_from_files(input_files):
    """Main function to generate QML from prompts read from input files and print them to the terminal."""
    try:
        for input_file in input_files:
            print(f"Processing file: {input_file}")
            # Read the prompt from the input file
            with open(input_file, 'r') as file:
                prompt = file.read()
            
            response_lines = generate_qml_code(prompt)
            generated_code = parse_response(response_lines)
            
            print("Output ................................................................:")
            print(generated_code)
        
    except Exception as e:
        print(f"An error occurred: {e}")


# Example usage:
if __name__ == "__main__":
    input_files = [
        "/home/mohammad/Documents/03,Lebenslauf/Code-Practis-C++/my_project/qml/Main.qml",  # Path to your first input file
        "/home/mohammad/Documents/03,Lebenslauf/Code-Practis-C++/my_project/MyClass.cpp",  # Path to your second input file
    ]
    generate_qml_from_files(input_files)
