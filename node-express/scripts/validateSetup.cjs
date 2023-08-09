const Joi =  require('joi');
const fs =  require('fs');
const dotenv = require('dotenv');

const envSchema = Joi.object({
  PORT: Joi.string().regex(/^\d+$/).message("PORT number should be numeric").required(),
  BASE_URL: Joi.string().required(),
});

// get all .env files except .env.example
const files = fs.readdirSync(process.cwd(), {recursive: false}).filter(file => (/\.env(?!\.(example))(\.\w+)?/).test(file));

files.forEach((file) => {
  const envBuf = fs.readFileSync(file, {encoding: 'utf8'});

  const config = dotenv.parse(envBuf);

  const {error} = envSchema.validate(config);

  if(error) {
    console.log('\x1b[41m%s\x1b[0m', file);
    console.log('\x1b[31m%s\x1b[0m', error.message);
  } else {
    console.log('\x1b[42m%s\x1b[0m', file, 'is valid');
  }
});
