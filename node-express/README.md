# Todo list server (Node.js & Express)

This repo contains the source code for REST serer created using nodejs using express framework

# Requirements

## Ensure the following programs are installed:
- Node.js

## Setting up env files
Follow the following steps 
**Production Environment**
- Create file named `.env`
- Copy the contents of `.env.example` provided in the repo and replace the variables with relevant value

**Creating different environments**
To create different environment files you only need to create a file named with this format `env.*` (* can be replaced by the environment name).
Make sure to add a relevant script for it in `package.json`. Refer the script for `development` environment

Example: For creating a development environment, create a file named `.env.development`, the contents of the file would be:

```sh
PORT=3000
BASE_URL=localhost
```

### Validating setup
After you've setup your env files run the following the command to check if the files are correct or not

```sh
npm run validate-setup
```

This will output any errors with your env files

# Running the project in dev mode

```sh
npm run dev
```

# Running the prject in production mode

```sh
npm run start
```
