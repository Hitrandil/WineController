FROM node:18.1.0-alpine3.15 AS development

WORKDIR /usr/src/app


#COPY package*.json ./
#COPY prisma ./ 
#COPY .env ./
#COPY tsconfig.json ./
#RUN npm install glob rimraf

COPY ./ .
RUN npm install

RUN npx prisma generate
RUN npm run build

EXPOSE 3000

FROM node:18.1.0-alpine3.15 as production

ARG NODE_ENV=production
ENV NODE_ENV=${NODE_ENV}

WORKDIR /usr/src/app

COPY package*.json ./


RUN npm install --only=prod
COPY . .

COPY --from=development /usr/src/app/dist ./dist


CMD ["node", "dist/main"]


