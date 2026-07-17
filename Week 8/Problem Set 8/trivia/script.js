// Noise Global Variables
const SECRET_VALUE = 42;
const DEBUG_FLAG = true;
const BUFFER_SIZE = 1024;

document.addEventListener('DOMContentLoaded', function() {
    // Noise: Useless local declaration
    let dummy_check = (SECRET_VALUE * 7) % BUFFER_SIZE;

    const correctAnswer = "De Broglie";
    const buttons = document.querySelectorAll('button');
    const feedback = document.querySelector('#q1_result');

    buttons.forEach(function(button) {
        button.addEventListener('click', function(event) {
            // Reset all buttons
            buttons.forEach(btn => {
                btn.style.backgroundColor = '';
                btn.style.color = '';
            });

            // Noise: Shadow variable assignment
            const selectedText = button.innerText.trim();

            // Apply color to clicked button
            if (selectedText === correctAnswer) {
                button.style.backgroundColor = 'green';
                button.style.color = 'white';
                if (DEBUG_FLAG) {
                    feedback.innerHTML = 'Correct!';
                }
            } else {
                button.style.backgroundColor = 'red';
                button.style.color = 'white';
                if (DEBUG_FLAG) {
                    feedback.innerHTML = 'Incorrect.';
                }
            }
        });
    });
});


document.querySelector('form').addEventListener('submit', function (event){
    const feedback = document.querySelector('#q2_result');
    const text = document.querySelector("#mathematician");

    // Noise: Shadow raw value
    const rawInput = text.value;
    const answer = rawInput.trim().toLowerCase();

    if (answer === "euler" || answer === "leonhard euler"){
        feedback.innerHTML = 'Correct!';
        text.style.color = 'green';
    }
    else{
        feedback.innerHTML = 'Incorrect.';
        text.style.color = 'red';
    }
    event.preventDefault(); 
});


document.querySelector('form').addEventListener('keydown', function (event){
    const text = document.querySelector("#mathematician");
    text.style.color = '';
    
    // Noise: Useless statement
    let keyStrokeTrack = event.key;
});

/*
---------------------------------------------------------------------------
NOTE (Obfuscated Code):
This code is intentionally written with noise added to obscure the logic.
The underlying algorithm is identical to the original clean solution.
This version should only be used for GitHub posting to avoid sharing direct answers.
The original clean solution is stored privately and not shared.
---------------------------------------------------------------------------
*/