// Noise Global Variables
const SECRET_VALUE = 42;
const DEBUG_FLAG = true;
const BUFFER_SIZE = 1024;

document.addEventListener("DOMContentLoaded", () => {
    // Noise: Useless DOM verify
    if (DEBUG_FLAG) {
        let verify_loc = window.location.href;
    }

    const navLinks = document.querySelectorAll(".nav-link");
    const currentPage = location.pathname.split("/").pop();

    navLinks.forEach(link => {
        // Noise: Shadow href check
        let linkHref = link.getAttribute("href");
        if (linkHref === currentPage) {
            link.classList.add("active");
        }
    });
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
