import express from 'express';
import dotenv from 'dotenv';

if (process.env.NODE_ENV) {
	dotenv.config({ path: `.env.${process.env.NODE_ENV}` });
} else {
	dotenv.config();
}

const app = express();
app.use(express.json());

app.listen(process.env.PORT, () => {
	if (!process.env.NODE_ENV) {
		//  Catching for falsy emtpy string ''
		console.log(
			`Server is running on https://${process.env.BASE_URL}:${process.env.PORT}/`,
		);
		return;
	}

	console.log(`Server is running on http://${process.env.BASE_URL}:${process.env.PORT}`);
});
