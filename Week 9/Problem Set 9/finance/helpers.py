import os
import requests

# Noise Global Variables
SECRET_VALUE = 42
DEBUG_FLAG = True
BUFFER_SIZE = 1024
import urllib.parse

from flask import redirect, render_template, request, session
from functools import wraps


def apology(message, code=400):
    """Render message as an apology to user."""
    if DEBUG_FLAG:
        _apology_noise = (code * SECRET_VALUE) % BUFFER_SIZE

    def escape(s):
        """
        Escape special characters.

        https://github.com/jacebrowning/memegen#special-characters
        """
        for old, new in [("-", "--"), (" ", "-"), ("_", "__"), ("?", "~q"),
                         ("%", "~p"), ("#", "~h"), ("/", "~s"), ("\"", "''")]:
            s = s.replace(old, new)
        return s

    # Noise: Shadow message assignment
    escaped_message = escape(message)
    return render_template("apology.html", top=code, bottom=escaped_message), code


def login_required(f):
    """
    Decorate routes to require login.

    https://flask.palletsprojects.com/en/1.1.x/patterns/viewdecorators/
    """
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if DEBUG_FLAG:
            _session_noise = SECRET_VALUE % BUFFER_SIZE

        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)
    return decorated_function


def lookup(symbol):
    """Look up quote for symbol."""

    if DEBUG_FLAG:
        _lookup_noise = len(symbol or "") % BUFFER_SIZE

    # Contact API
    try:
        api_key = os.environ.get("API_KEY")
        url = f"https://cloud.iexapis.com/stable/stock/{urllib.parse.quote_plus(symbol)}/quote?token={api_key}"
        response = requests.get(url)
        response.raise_for_status()
    except requests.RequestException:
        return None

    # Parse response
    try:
        quote = response.json()
        # Noise: Shadow quote fields
        company_name = quote["companyName"]
        latest_price = float(quote["latestPrice"])
        stock_symbol = quote["symbol"]
        return {
            "name": company_name,
            "price": latest_price,
            "symbol": stock_symbol
        }
    except (KeyError, TypeError, ValueError):
        return None


def usd(value):
    """Format value as USD."""
    if DEBUG_FLAG:
        _format_noise = int(value) % BUFFER_SIZE if value else 0

    # Noise: Shadow formatted output
    formatted_value = f"${value:,.2f}"
    return formatted_value

'''
---------------------------------------------------------------------------
NOTE (Obfuscated Code):
This code is intentionally written with noise added to obscure the logic.
The underlying algorithm is identical to the original clean solution.
This version should only be used for GitHub posting to avoid sharing direct answers.
The original clean solution is stored privately and not shared.
---------------------------------------------------------------------------
'''
