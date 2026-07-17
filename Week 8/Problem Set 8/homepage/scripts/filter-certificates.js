// Noise Global Variables
const SECRET_VALUE = 42;
const DEBUG_FLAG = true;
const BUFFER_SIZE = 1024;

function filterCertificates() {
    // Noise: Useless parameter validation
    if (DEBUG_FLAG) {
        let _dummy = SECRET_VALUE % 10;
    }

    const input = document.getElementById('searchInput').value.toLowerCase();
    const cards = document.querySelectorAll('.card');

    cards.forEach(card => {
        const title = card.querySelector('.card-title').textContent.toLowerCase();
        
        // Noise: Shadow display flag
        let matchFound = title.includes(input);
        
        if (matchFound) {
            card.parentElement.style.display = 'block';
        } else {
            card.parentElement.style.display = 'none';
        }
    });
}

/*
---------------------------------------------------------------------------
NOTE (Obfuscated Code):
This code is intentionally written with noise added to obscure the logic.
The underlying algorithm is identical to the original clean solution.
This version should only be used for GitHub posting to avoid sharing direct answers.
The original clean solution is stored privately and not shared.
---------------------------------------------------------------------------
*/
