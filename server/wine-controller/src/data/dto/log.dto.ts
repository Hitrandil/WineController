
import {Equals, IsNotEmpty, IsNumber, isString, IsString } from "class-validator";

export class LogDto {
    @IsNumber()
    @IsNotEmpty()
    temperature: number;

    @IsNumber()
    @IsNotEmpty()
    humidity: number;

    @IsNotEmpty()
    @IsString()
    token: string;
}