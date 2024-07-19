import os
import json
import requests


#This need always to be fixed always regarding the output of the google.colab
os.environ["OLLAMA_HOST"] = "https://1c9f-34-138-3-230.ngrok-free.app"

OLLAMA_HOST = os.getenv("OLLAMA_HOST")
if not OLLAMA_HOST:
    raise EnvironmentError("OLLAMA_HOST environment variable not set. Please set it to the ngrok URL.")

def generate_qml_code(prompt):
    """Generates QML code by sending the prompt to the API."""
    url = os.getenv("OLLAMA_HOST", "http://localhost:11434") + "/api/generate"
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


def generate_qml_from_file(input_file):
    """Main function to generate QML from a prompt read from an input file and print it to the terminal."""
    try:
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
    input_file = "/home/mohammad/Documents/03,Lebenslauf/Code-practis/Code-Practis-C++/my_project/qml/Main.qml"  # Replace with the path to your input QML file
    generate_qml_from_file(input_file)