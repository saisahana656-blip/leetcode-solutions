# Authentication: Components, Request Flow, Credentials, and Tokens

## 1. Scope of this repository

This repository contains LeetCode practice solutions. It does **not** implement an authentication server or contain LeetCode's private authentication code. The assignment handout describes signing in to LeetCode with an account and using Git with GitHub; it does not specify LeetCode's internal token format or authentication endpoints.

The notes below distinguish sign-in concepts from authentication used when pushing this repository to GitHub. The OAuth-style flow is a general educational model, not a claim about LeetCode's exact internal implementation.

## 2. Main components

- **User / browser:** starts sign-in and uses the service.
- **Identity provider:** verifies an account when a third-party sign-in option is selected.
- **Application server:** checks the authentication result and decides which resources the user may access.
- **Session or token:** evidence used by later requests to associate them with an authenticated user.
- **Git client:** sends commits to GitHub when the repository is pushed.
- **GitHub authentication:** HTTPS credentials managed by a credential helper, or an SSH key, authorize Git operations according to account permissions.

Authentication answers “Who are you?” Authorization answers “What are you allowed to do?”

## 3. General sign-in request flow

1. The user selects a sign-in option and enters credentials only on the provider's official page.
2. The provider verifies the credentials and any required second factor.
3. In a typical delegated sign-in flow, the application receives a short-lived authorization result or code through a registered redirect.
4. The application exchanges or validates that result using its server-side configuration.
5. The application establishes a session or receives a token according to its design.
6. Later requests include the session cookie or appropriate token.
7. The server validates the session/token, checks authorization, and returns the resource or an authentication error.

Exact redirects, cookies, token types, lifetimes, and endpoints depend on the service. They are not discoverable from this repository's solution files.

## 4. GitHub request flow for this repository

1. You edit and commit files locally.
2. `git push` contacts the GitHub remote URL.
3. Git authenticates using the configured HTTPS credential helper (typically with a token) or an SSH key.
4. GitHub validates the credential and checks repository permissions.
5. If authorized, GitHub accepts the push; otherwise it rejects it.

A repository URL is not itself a credential. Do not paste passwords or tokens into source files or chat.

## 5. Safe illustrative code

For an API that explicitly documents Bearer-token authentication, a client might send a token from an environment variable like this:

```python
import os
import requests

token = os.environ.get("SERVICE_API_TOKEN")
if not token:
    raise RuntimeError("Set SERVICE_API_TOKEN in your environment")

response = requests.get(
    "https://api.example.com/profile",  # Placeholder; use a documented API URL
    headers={"Authorization": f"Bearer {token}"},
    timeout=10,
)
response.raise_for_status()
print(response.json())
```

This is an **illustrative generic example**, not a working LeetCode API integration. `api.example.com` is a placeholder. Use only official, documented endpoints and the authentication method they specify. Never hard-code a real token.

## 6. Credentials and token handling

- Enter passwords only on the official sign-in page; never store plaintext passwords in this repository.
- Do not commit access tokens, refresh tokens, session cookies, API keys, SSH private keys, or `.env` files.
- Keep secrets in environment variables or an approved secret manager, and ensure local secret files are ignored by Git.
- Use the minimum permissions needed. Revoke a credential immediately if it is exposed.
- Tokens may be scoped, expire, and be revoked; clients should handle authentication failures rather than repeatedly retrying invalid credentials.
- Use HTTPS for network requests. Avoid printing tokens or authorization headers in logs.
- Prefer Git Credential Manager or SSH keys for GitHub Git operations; never place a personal access token directly in a remote URL or source code.

## 7. Troubleshooting GitHub authentication

- For HTTPS, sign in through the credential manager and follow GitHub's current authentication prompts.
- For SSH, add your public key to GitHub and keep the private key on your own device.
- Confirm that the authenticated account has write access to this repository.
- If a token or key is exposed, revoke or replace it; deleting the visible line in a later commit does not remove it from Git history.

## 8. What this repository does and does not prove

The code in the topic folders solves algorithm problems. It does not contain a login endpoint, credential database, token issuer, token validator, or protected API. To explain the real internal authentication implementation of a different repository, inspect that repository's authentication code and documentation rather than infer it from a solutions portfolio.
