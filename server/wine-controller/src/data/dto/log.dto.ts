
import {Equals, IsNotEmpty, IsNumber, isString, IsString } from "class-validator";

export class LogDto {
    @IsNotEmpty()
    temperature: string;

    @IsNotEmpty()
    humidity: string;

    @IsNotEmpty()
    @IsString()
    token: string;
}
