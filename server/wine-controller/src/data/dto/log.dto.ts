
import {Equals, IsNotEmpty, IsNumber, isString, IsString } from "class-validator";

export class LogDto {
    @IsNotEmpty()
    temperature: number;

    @IsNotEmpty()
    humidity: number;

    @IsNotEmpty()
    @IsString()
    token: string;
}
